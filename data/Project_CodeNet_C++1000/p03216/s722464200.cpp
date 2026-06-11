#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    int Q;
    cin >> N >> S >> Q;
    vector<int> K(Q);
    for (auto& k : K) {
        cin >> k;
    }
    for (auto& k : K) {
        ll d_cnt = 0;
        ll m_cnt = 0;
        ll dm_cnt = 0;
        ll ans = 0;
        rep(i, 0, N) {
            if (i >= k) {
                if (S[i - k] == 'D') {
                    --d_cnt;
                    dm_cnt -= m_cnt;
                } else if (S[i - k] == 'M') {
                    --m_cnt;
                }
            }
            if (S[i] == 'D') {
                ++d_cnt;
            } else if (S[i] == 'M') {
                ++m_cnt;
                dm_cnt += d_cnt;
            } else if (S[i] == 'C') {
                ans += dm_cnt;
            }
        }
        cout << ans << endl;
    }
    return 0;
}