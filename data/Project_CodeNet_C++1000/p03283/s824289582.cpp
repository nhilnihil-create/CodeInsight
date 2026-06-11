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
	int n,m,q;
	int ans=0;
	cin >>n>>m>>q;
	VVi dis(n+2,Vi(n+2,0));
	int l,r;
	rep(i,m){
		cin>>l>>r;
		//l--;
		//r--;
		dis[l][r]++;
		//dis[l][l]++;
		//dis[l][r+1]--;
		//dis[r+1][l]--;
		//dis[r+1][r+1]++;
	}
	rep(i,n+1){
		rep(j,n+1){
			if(j!=0){
				dis[i][j]+=dis[i][j-1];
			}
		}
	}
	rep(i, n+1){
		
		rep(j, n+1){
			if (i != 0)
			{
				dis[i][j] += dis[i - 1][j];
			}
		//	clog<<dis[i][j]<<" ";
		}
	//	clog<<endl;
	}
	rep(i,q){
		cin>>l>>r;
		//l--;
		//r--;
		cout<<dis[r][r]-dis[l-1][r]-dis[r][l-1]+dis[l-1][l-1]<<endl;
	}
}
/*
  a----b en
a 01 -1 
- 00 01
- -1
-
b
st
*/