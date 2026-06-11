#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n;
	int ans=0;
	cin >>n;
	vector<int> a(n),b(n);
	vector<int> suma(n+1,0),sumb(n+1,0);
	rep(i,n){
		cin>>a[i];
		if(i!=0){
			suma[i]+=suma[i-1];
		}
		suma[i]+=a[i];
		clog<<suma[i]<<" ";
	}
	clog<<endl;
	rep(i, n)
	{
		cin >> b[i];
	}
	clog<<endl;
	for(int i=n-1;i>=0;i--){
		sumb[i]+=sumb[i+1];
		sumb[i]+=b[i];
		clog<<sumb[i]<<" ";
	}
	rep(i,n){
		chmax(ans,suma[i]+sumb[i]);
	}
	cout<<ans<<endl;
}