#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef pair<int , int> i_i;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<ll>> ve_vel;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) *max_element(all(a))
#define minel(a) *min_element(all(a))
#define acc accumulate
#define EPS (1e-7)
//#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)
typedef long long int64;
const int64 INF = 1LL << 58;
#define dame { puts("-1"); return 0;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int N, K, x[55], y[55];
int main() {
	cin >> N >> K;
	rep(i,N) cin >> x[i] >> y[i];
	long long ret = 1LL << 62;
	rep(i,N) rep(j,N) rep(k,N) rep(l,N) {
        if (x[i] <= x[j] && y[k] <= y[l]) {
            int cnt = 0;
            for (int p = 0; p < N; p++) {
                if (x[i] <= x[p] && x[p] <= x[j] && y[k] <= y[p] && y[p] <= y[l]) cnt++;
            }
            if (cnt >= K) ret = min(ret, 1LL * (x[j] - x[i]) * (y[l] - y[k]));
        }
	}
	cout << ret << endl;
	return 0;
}