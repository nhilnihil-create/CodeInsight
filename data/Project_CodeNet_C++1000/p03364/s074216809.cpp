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
#define YES { cout << "YES" << endl; return 0; }
#define NO { cout << "NO" << endl; return 0; }
#define Yes { cout << "Yes" << endl; return 0; }
#define No { cout << "No" << endl; return 0; }
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    int N; cin >> N;
    ves S(N); rep(i,N) cin >> S[i];
    int cnt = 0;
    rep(A,1) rep(B,N) {
        bool flag = true;
        rep(i,N) {
            repk(j,i+1,N) {
                if(S[(i+A)%N][(j+B)%N] != S[(j+A)%N][(i+B)%N]) { flag = false; break;}
            }
            if(!flag) break;
        }
        if(flag) cnt++;
    }
    cout << cnt * N << endl;
    return 0;
}