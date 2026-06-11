#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define Dcout(a) cout << setprecision(20) << a << endl
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using ll = long long;
using PAIR = pair<int, int>;
using Graph = vector<vector<int>>;
const ll INF = (1LL << 60);
const double pi=acos(-1.0);
#define debug cout << "line : " << __LINE__ << " debug" << endl
/****** Template of some basic operations *****/
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/**************************************/
/******** User-defined Function *******/

/**************************************/
/********** Main()  function **********/
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m; cin >> n >> m;
    int ans = 0;
    vector<int> k(m);
    vector<vector<int>> s;
    rep(i,m){
        vector<int> a;
        cin >> k[i];
        rep(j,k[i]){
            int b; cin >> b;
            a.push_back(b-1);
        }
        s.push_back(a);
    }

    vector<int> p(m);
    rep(i,m) cin >> p[i];

    rep(bit,(1<<n)){
        bool flag = true;
        rep(i,m){
            int cnt = 0;
            rep(j,k[i]){
                if(bit & (1<<s[i][j])) cnt++;
            }
            if(cnt%2!=p[i]){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }

    cout << ans << endl;

}
/********  Main() Ends Here *************/
