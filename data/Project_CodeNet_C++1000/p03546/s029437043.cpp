#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define srt(x) sort((x).begin(), (x).end());
#define rsrt(x) sort((x).rbegin(), (x).rend());
#define deb(x) cout<<#x<<" = "<<(x)<<" (L"<<LINE<<")"<<endl;
#define vdeb(x) {cout<<#x<<" = { "; rep(i, x.size()) cout<<x[i]<<' '; cout <<'}'<<" (L"<<LINE<<")"<<endl;}
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vivi = vector<vi>;
using vll = vector<long long>;
using vllvll = vector<vll>;
using vs = vector<string>;
using um = unordered_map<long long, long long>;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;

int main()
{
    ll H, W;
    cin >> H >> W;
    vllvll c(10, vll(10));
    rep(i, 0, 10) {
        rep(j, 0, 10) {
            cin >> c[i][j];
        }
    }
    vllvll A(H, vll(W));
    rep(i, 0, H) {
        rep(j, 0, W) {
            cin >> A[i][j];
        }
    }

    rep(k, 0, 10) {
        rep(i, 0, 10) {
            rep(j, 0, 10) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    ll sm = 0;
    rep(i, 0, H) {
        rep(j, 0, W) {
            if (A[i][j] == -1) continue;
            sm += c[A[i][j]][1];
        }
    }
    cout << sm << endl;
}