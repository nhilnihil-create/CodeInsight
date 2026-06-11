#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){
	int len=d.size();
	rep(i,len){
		s<<d[i];if(i<len-1) s<<" ";
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){
	int len=d.size();
	rep(i,len){
		s<<d[i]<<endl;
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){
	s<<"{ ";
	for(auto itr=v.begin();itr!=v.end();++itr) {
		if (itr!=v.begin()) {s<< ", ";}
		s<<(*itr);
	}
	s<<" }";
	return s;
}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){
	s<<"{"<<endl;
	for(auto itr=m.begin();itr!=m.end();++itr){
		s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;
	}
	s<<"}"<<endl;
	return s;
}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

//a,bの最大公約数
template <class T>
T gcd(T a,T b) {
	if (b==0) return a;
	else return gcd(b,a%b);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	auto no=[](){cout<<"No"<<endl;};
	auto yes=[](){cout<<"Yes"<<endl;};
	while(t--){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b>a){//初日から在庫が足りない
			no();
			continue;
		}
		if(d<b){//在庫の追加が追いつかない
			no();
			continue;
		}
		if(b==d){//cが適切なら無限ループに落とし込める
			if(a%b<=c){
				yes();
			}else{
				no();
			}
			continue;
		}
		//以下, a>=b,d>bのケースを考える
		if(b<=c){//残りがbより少なくなったら追加可能なので常にok
			yes();
			continue;
		}
		//c<bのケース
		ll g=gcd(b,d);
		ll k=(b-a%g+g-1)/g-1;
		if(a%g+g*k<=c) yes();
		else no();
	}
}