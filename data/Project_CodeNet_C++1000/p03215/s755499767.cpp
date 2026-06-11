#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), C;

    rep(i, N) {
        cin >> A[i];
    }

    ll nax = 0;

    rep(i, N) {
        C.push_back(A[i]);
        ll sum = A[i];
        repd(j, i + 1, N) {
            sum += A[j];
            C.push_back(sum);
            chmax(nax, sum);
        }
    }

    ll st;
    set<ll> ansset;
    for (ll bit = 1; bit <= nax; bit <<= 1) {
        ll cnt = 0;
        rep(i, C.size()) {
            if (C[i] & bit) {
                cnt++;
            }
        }
        if (cnt >= K) {
            st = bit;
        }
    }

    rep(i, C.size()) {
        if (C[i] & st) {
            ansset.insert(C[i]);
        }
    }

    for (ll bit = st; bit > 0; bit >>= 1) {
        ll cnt = 0;
        for (auto itr = ansset.begin(); itr != ansset.end(); itr++) {
            if (*itr & bit) {
                cnt++;
            }
        }
        set<ll> tmp;
        if (cnt >= K) {
            for (auto itr = ansset.begin(); itr != ansset.end(); itr++) {
                if (*itr & bit) {
                    tmp.insert(*itr);
                }
            }
            ansset = tmp;
            tmp.clear();
        }
    }

    ll ans = 0;
    for (auto itr = ansset.begin(); itr != ansset.end(); itr++) {
        if (ans == 0) {
            ans = *itr;
        }
        else {
            ans &= *itr;
        }
    }

    cout << ans << endl;
    return 0;
}