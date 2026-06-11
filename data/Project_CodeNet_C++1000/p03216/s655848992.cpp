#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

using P = pair<char, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    string S;
    cin >> N >> S >> Q;
    vector<int> K(Q);
    for (auto& k : K) {
        cin >> k;
    }
    for (auto& k : K) {
        queue<P> que;
        ll ans = 0;
        ll stock = 0;
        ll d_cnt = 0, m_cnt = 0;
        rep(i, 0, N) {
            while (que.size()) {
                if (que.front().first == 'D' && que.front().second <= i - k) {
                    que.pop();
                    stock -= m_cnt;
                    --d_cnt;
                }
                else if (que.front().first == 'M') {
                    que.pop();
                    --m_cnt;
                }
                else {
                    break;
                }
            }
            if (S[i] == 'D') {
                que.push(P(S[i], i));
                ++d_cnt;
            }
            else if (S[i] == 'M') {
                que.push(P(S[i], i));
                ++m_cnt;
                stock += d_cnt;
            }
            else if (S[i] == 'C') {
                ans += stock;
            }
        }
        cout << ans << endl;
    }
    return 0;
}