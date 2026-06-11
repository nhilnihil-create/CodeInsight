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
const int INF = 1<<27;
const double PI=acos(-1);
int main(){
	int n,a,b,c;
	int ans=INF;
	cin >>n>>a>>b>>c;
	Vi l(n);
	Vi g(3);
	g[0]=a;
	g[1] = b;
	g[2] = c;
	rep(i,n){
		cin>>l[i];

	}
	Vi legth(3,0);
	Vi cost(3,0);
	int id;
	rep(bit,1<<(n*2)){
		rep(i,3){
			legth[i]=0;
			cost[i]=-10;
		}
		for(int i=0;i<n*2;i+=2){
			if(bit&(1<<i)){
				id=1;
			}else{
				id=0;
			}
			if (bit & (1 << (i+1)))
			{
				id += 2;
			}
			if(id!=3){
				legth[id]+=l[i/2];
				cost[id]+=10;
			}
		}
		rep(i,3){
			if(legth[i]==0){
				cost[i]=INF;
			}else{
				cost[i]+=abs(legth[i]-g[i]);
			}
		}
		chmin(ans,cost[1]+cost[2]+cost[0]);
	}
	cout<<ans<<endl;
}