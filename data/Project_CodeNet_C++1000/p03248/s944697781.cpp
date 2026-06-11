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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    if (S.front() == '0' || S.back() == '1') {
        cout << -1 << endl;
        return 0;
    }
    int N = (int)S.size() - 1;
    rep(i, 0, N / 2) {
        if (S[i] != S[N - i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    queue<int> que;
    que.push(1);
    rep(i, 1, N) {
        if (S[i] == '1') {
            while (!que.empty()) {
                cout << i + 1 << ' ' << que.front() << endl;
                que.pop();
            }
        }
        que.push(i + 1);
    }
    while (!que.empty()) {
        cout << N + 1 << ' ' << que.front() << endl;
        que.pop();
    }
    return 0;
}