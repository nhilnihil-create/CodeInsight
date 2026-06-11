#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int K;
    cin >> K;
    vector<ll> A(K);
    rep(i, K) cin >> A[i];
    ll mi = A[K - 1], ma = A[K - 1] * 2 - 1;
    for (int i = K - 2; i >= 0; i--) {
        if (mi < A[i]) mi = A[i];
        else {
            mi = A[i] * ((mi + A[i] - 1) / A[i]);
        }
    }

    for (int i = K - 2; i >= 0; i--) {
        ma = A[i] * ((ma / A[i]) + 1) - 1;
    }

    ll gmi = mi, gma = ma;
    rep(i, K) {
        gmi -= (gmi % A[i]);
        gma -= (gma % A[i]);
    }

    if (gmi == 2 && gma != 2) {
        ma = mi;
    }
    else if (gmi != 2 && gma == 2) {
        mi = ma;
    } 
    else if (gmi != 2 && gma != 2) {
        cout << -1 << endl;
        return 0;
    }

    cout << mi << " " << ma << endl;
    return 0;
}