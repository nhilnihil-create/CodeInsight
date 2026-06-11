//code by lynmisakura.wish to be accepted
/****************************/
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<vector>
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
/***************************/
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;

const long long Mod = 998244353;
const long long mod = 1000000007;
const long long INF = 10000000000000;

#define pb push_back
#define mp make_pair
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
	
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { int ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }

#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
/***************************/
int n,q;
string s;
char t[200010],d[200010];
int over(int x){
	int p = x;
	rep(i,q){
		int dd = 0;
		if(t[i] == s[p]){
			if(d[i] == 'R') dd++;
			else dd--;
		}
		p += dd;
		if(p < 1) return -1;
		if(p > n) return 1;
	}
	return 0;
}
int main(void){
	cin >> n >> q >> s;
	rep(i,q){
		cin>>t[i]>>d[i];
	}
	s.insert(s.begin(),'?');
	s.push_back('?');
	//左から落ちる最右点を求める
	int l = 0,r = n+1;
	int mid;
	rep(i,100){
		mid = (l+r)/2;
		if(over(mid) >= 0){
			r = mid;
		}else{
			l = mid;
		}
	}
	//cout << l << " " << mid << " " << r << endl;
	int left_bound;
	if(over(r) == -1) left_bound = r; else left_bound = l;
	//右から落ちる最左点を求める
	l = 0,r = n+1;
	rep(i,100){
		mid = (l+r)/2;
		if(over(mid) <= 0){
			l = mid;
		}else{
			r = mid;
		}
	}
	int right_bound;
	if(over(l) == 1) right_bound = l; else right_bound = r;
	//cout << left_bound << " " << right_bound << endl;
	cout << right_bound - left_bound - 1<< endl;
	return 0;
}