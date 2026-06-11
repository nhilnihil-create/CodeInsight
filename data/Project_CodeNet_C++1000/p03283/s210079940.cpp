#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<62;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n,m,q;
	int ans=0;
	cin >>n>>m>>q;
	/*
	data:[begin][end]: 
	*/
	vector<vector<int>>data(n+4,vector<int>(n+4,0));//start,end
	int l,r;
	rep(i,m){
		cin>>l>>r;
		data[l][r]++;
	}
	for(int i=n+1;i>=0;i--){
		rep(j,n+1){
			data[i][j]+=data[i+1][j];
		}
	}
	rep(i,n+1){
		rep(j,n+1){
			data[i][j+1]+=data[i][j];
		}
	}
	rep(i,q){
		cin>>l>>r;
		cout<<data[l][r]<<endl;
	}
//	cout<<ans<<endl;
}