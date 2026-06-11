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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, 0, H) rep(j, 0, W) {
        cin >> A[i][j];
    }
    vector<int> y1, x1, y2, x2;
    bool exist = false;
    rep(i, 0, H) {
        if (i % 2) {
            rrep(j, W, 0) {
                if (A[i][j] % 2) {
                    if (exist) {
                        exist = false;
                        y2.push_back(i);
                        x2.push_back(j);
                    } else {
                        exist = true;
                        y1.push_back(i);
                        x1.push_back(j);
                    }
                }
            }
        } else {
            rep(j, 0, W) {
                if (A[i][j] % 2) {
                    if (exist) {
                        exist = false;
                        y2.push_back(i);
                        x2.push_back(j);
                    } else {
                        exist = true;
                        y1.push_back(i);
                        x1.push_back(j);
                    }
                }
            }
        }
    }
    int N = min(y1.size(), y2.size());
    vector<int> Y, X;
    int idx = 0;
    bool is_ok = false;
    vector<int> Y1, X1, Y2, X2;
    rep(i, 0, H) {
        if (i % 2) {
            rrep(j, W, 0) {
                if (idx < N && i == y1[idx] && j == x1[idx]) {
                    is_ok = true;
                }
                if (is_ok) {
                    Y.push_back(i);
                    X.push_back(j);
                }
                if (idx < N && i == y2[idx] && j == x2[idx]) {
                    ++idx;
                    is_ok = false;
                    rep(k, 0, Y.size() - 1) {
                        Y1.push_back(Y[k]);
                        X1.push_back(X[k]);
                        Y2.push_back(Y[k + 1]);
                        X2.push_back(X[k + 1]);
                    }
                    Y.clear();
                    X.clear();
                }
            }
        } else {
            rep(j, 0, W) {
                if (idx < N && i == y1[idx] && j == x1[idx]) {
                    is_ok = true;
                }
                if (is_ok) {
                    Y.push_back(i);
                    X.push_back(j);
                }
                if (idx < N && i == y2[idx] && j == x2[idx]) {
                    ++idx;
                    is_ok = false;
                    rep(k, 0, Y.size() - 1) {
                        Y1.push_back(Y[k]);
                        X1.push_back(X[k]);
                        Y2.push_back(Y[k + 1]);
                        X2.push_back(X[k + 1]);
                    }
                    Y.clear();
                    X.clear();
                }
            }
        }
    }
    cout << Y1.size() << endl;
    rep(i, 0, Y1.size()) {
        cout << Y1[i] + 1 << ' ' << X1[i] + 1 << ' ' << Y2[i] + 1 << ' ' << X2[i] + 1 << endl;
    }
    return 0;
}