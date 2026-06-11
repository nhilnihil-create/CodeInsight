#include <iostream>
//#include <iomanip>
//#include <string>
#include <vector>
#include <algorithm>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
//#include <deque>
//#include <bitset>
//#include <math.h>
using namespace std ;
using ll = long long ;
//using ld = long double ;
using vll = vector<ll> ;
//using vvll = vector<vll> ;
//using vc = vector<char> ;
//using vvc = vector<vc> ;
//using vb = vector<bool> ;
//using vvb = vector<vb> ;
//using pll = pair<ll,ll> ;
//#define all(v) v.begin(),v.end()
//ll mod = 1e9+7 ;
//long double pie = acos(-1) ;
ll INF = 1000000000000 ;

//void yorn(bool a){if(a) cout << "Yes" << endl ; else cout << "No" << endl ;}
//void YorN(bool a){if(a) cout << "YES" << endl ; else cout << "NO" << endl ;}
ll gcd(long long a,long long b){if(b==0) return a ; return gcd(b,a%b) ;}
//ll lcm(long long a,long long b){return a/gcd(a,b)*b ;}
//ll sa(long long a,long long b){if(a>b) return a-b ; return b-a ;}
//void fix_cout(){cout << fixed << setprecision(20) ;}

const int MAX = 2000000 ;

//宣言するときはstaticをつけて静的変数にするかグローバル変数として宣言
//initのときに関数の種類を決定する（0:sum,1:min,2:max,3:gcd）
class SGT{
public :
	int n = 1;
	ll d ;
	ll num[MAX] ;
	int fan ;

//	指定された関数を実行する
	ll f(ll a,ll b){
		if(fan==0) return a+b ;
		else if(fan==1) return min(a,b) ;
		else if(fan==2) return max(a,b) ;
		else if(fan==3) return gcd(a,b) ;
		else return d ;
	}

	void d_set(int b){
		fan = b ;
		if(fan==0) d = 0 ;
		else if(fan==1) d = INF ;
		else if(fan==2) d = -INF ;
		else if(fan==3) d = 0 ;
	}

//	初期化する、bは関数の種類を指定する
	void init(vector<ll> &a,int b){
		d_set(b) ;
		while(a.size()>n) n *= 2 ;
		for(int i=0;i<n;i++){
			if(i<a.size()) num[n-1+i] = a.at(i) ;
			else num[n-1+i] = d ;
		}
		for(int i=n-2;i>=0;i--){
			num[i] = f(num[i*2+1],num[i*2+2]) ;
		}
	}

	void init(ll a,ll sz,int b){
		d_set(b) ;
		while(sz>n) n *= 2 ;
		for(int i=0;i<n;i++){
			if(i<sz) num[n-1+i] = a ;
			else num[n-1+i] = d ;
		}
		for(int i=n-2;i>=0;i--){
			num[i] = f(num[i*2+1],num[i*2+2]) ;
		}
	}

//	内容次第でwhile内の計算式を書き換える→書き換えなくて良くなった
	void update(int i,ll a){
		i += n-1 ;
		num[i] = a ;
		while(i>0){
			i = (i-1)/2 ;
			num[i] = f(num[i*2+1],num[i*2+2]) ;
		}
	}

//	最初に呼び出すときは[a,b)だけで十分
	ll query(int a,int b,int l=0,int r=-1,int now=0){
		if(r==-1) r = n ;
		if(r<=a||b<=l) return d ;
		if(a<=l&&r<=b) return num[now] ;
		ll r1 = query(a,b,l,(l+r)/2,now*2+1) ;
		ll r2 = query(a,b,(l+r)/2,r,now*2+2) ;
		return f(r1,r2) ;
	}
};

int main(){
	ll n ; cin >> n ;
	vll a(n) ;
	for(auto &i:a) cin >> i ;
	ll ans = 0 ;
	static SGT sgt ;
	sgt.init(a,3) ;
	for(int i=0;i<n;i++){
		ans = max(ans,gcd(sgt.query(0,i),sgt.query(i+1,n))) ;
	}
	cout << ans << endl ;
}
