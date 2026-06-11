#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define input(array) repi(_itr, array) { cin >> *(_itr); }
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
string solve(bool a) { return ((a) ? "Yes" : "No"); }
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
//ワーシャルフロイゼ法(隣接行列を受け取り、それぞれの最短を受け取る、size:10^2-)
vector<vector<int>> WarshallFloyd(vector<vector<int>> &pathmatrix){
	int index=pathmatrix.size();
	vector<vector<int >>res=pathmatrix;
	for (int a = 0; a < index; a++){
		for (int b = 0; b < index; b++){
			for (int c = 0; c < index; c++){ 
				chmin(res[b][c], res[b][a] + res[a][c]);
			}
		}
	}
	return (res);
}
int main(){
	int h,w;
	ll ans=0LL;
	cin >>h>>w;
	VVi c(10, Vi(10));
	rep(i, 10) { input(c[i]); }
	VVi res = WarshallFloyd(c);
	VVi a(h, Vi(w));
	map<int, int> dis;
	rep(i, h) { input(a[i]); }
	rep(i, h) {
		rep(j, w) { dis[a[i][j]]++; }
	}
	repi(itr, dis) {
		if (itr->F == -1) continue;
		ans += (ll)(itr->S) * res[itr->F][1]; }
	cout<<ans<<endl;
}