#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define input(array) repi(array##_itr, array) { cin >> *(array##_itr); }
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
int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	input(s);
	ll ans = 0;
	map<char, int> dis;
	rep(i, n) { dis[s[i][0]]++; }
	vector<char> ter;
	ter.push_back('M');
	ter.push_back('A');
	ter.push_back('R');
	ter.push_back('C');
	ter.push_back('H');
	rep(i, 5) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				ans +=(ll) dis[ter[i]] * dis[ter[j]] * dis[ter[k]];
			}
		}
	}
	cout<<ans<<endl;
}