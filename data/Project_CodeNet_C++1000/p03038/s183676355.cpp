#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<ll, ll> P;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<P> CB(M);
    rep(i, M) {
        int B, C;
        cin >> B >> C;
        CB[i] = {C, B};
    }

    sort(all(CB));
    reverse(all(CB));
    sort(all(A));

    ll cnt = 0;
    rep(i, M) {
        ll C = CB[i].first, B = CB[i].second;
        ll index = upper_bound(all(A), C) - A.begin();
        if (cnt < index) {
            cnt += min(index - cnt, B);
        }
        else break;
    }

    ll sum = 0;
    repd(i, cnt, N) sum += A[i];

    rep(i, M) {
        ll minus = min(cnt, CB[i].second);
        cnt -= minus;
        sum += max(0LL, minus) * CB[i].first;
    }

    cout << sum << endl;
    return 0;
}