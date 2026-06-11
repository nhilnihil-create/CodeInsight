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
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];

    set<int> st;
    rep(i, N) {
        if (st.count(P[i] - 1)) {
            st.erase(st.find(P[i] - 1));
        }
        st.insert(P[i]);
    }

    int ct = 0;
    int mlen = 0;
    for (auto itr : st) {
        chmax(mlen, itr - ct);
        ct = itr;
    }

    cout << N - mlen << endl;
    return 0;
}