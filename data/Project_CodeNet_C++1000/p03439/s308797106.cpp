#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int l=0,r=n-1,mid;
	vector<int> cnt(n,INF);
	auto check=[](string s){
		if(s=="Vacant"){
			return 0;
		}else if(s=="Male"){
			return 1;
		}else{
			return -1;
		}
	};
	string s;
	cout<<l<<endl;
	cin>>s;
	cnt[l]=check(s);
	if(cnt[l]==0){
		cout<<l<<endl;
		return 0;
	}
	cout<<r<<endl;
	cin>>s;
	cnt[r]=check(s);
	if(cnt[r]==0){
		cout<<r<<endl;
		return 0;
	}
	while(r-l>1){
		mid=(l+r)/2;
		cout<<mid<<endl;
		cin>>s;
		cnt[mid]=check(s);
		if(cnt[mid]==0){
			cout<<mid<<endl;
			return 0;
		}
		if((mid-l+1)%2==0){
			if(cnt[l]==cnt[mid]){
				r=mid;
			}else{
				l=mid;
			}
		}else{
			if(cnt[l]!=cnt[mid]){
				r=mid;
			}else{
				l=mid;
			}
		}
	}
}