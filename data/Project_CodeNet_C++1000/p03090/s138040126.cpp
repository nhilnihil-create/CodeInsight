#include<iostream>
#include<vector>
#include<string>
#include<set>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

using edge = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    set<edge> S;
    rep(i, 0, N) rep(j, i + 1, N) {
        S.insert(edge(i, j));
    }
    if (N % 2) {
        rep(i, 0, N - 1) {
            S.erase(edge(i, N - 2 - i));
        }
    } else {
        rep(i, 0, N) {
            S.erase(edge(i, N - 1 - i));
        }
    }
    cout << S.size() << endl;
    for (auto& e : S) {
        cout << e.first + 1 << ' ' << e.second + 1 << endl;
    }
    return 0;
}