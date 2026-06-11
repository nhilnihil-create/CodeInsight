#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define PI acos(-1)
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<typename T> using v2 = vector<vector<T>>;
template<typename T> using v3 = vector<vector<vector<T>>>;
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int MOD = 1e9 + 7;
const int INF = 1e9 + 200;
const ll INFLL = 2e18 + 200;

int main() {
    int N;
    cin >> N;
    vector<long> X(static_cast<unsigned long>(N)), Y(static_cast<unsigned long>(N));
    cin >> X[0] >> Y[0];
    bool check = ((X[0] + Y[0]) % 2 == 0);
    for (int i = 1; i < N; ++i) {
        cin >> X[i] >> Y[i];
        if (check != (((X[i]) + Y[i]) % 2 == 0)) {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<long> d(34);
    int dLength = 33;
    if (!check) {
        cout << dLength << endl;
        for (int i = 0; i <= 32; ++i) {
            d[i] = static_cast<long>(pow(2, i));
            cout << d[i] << " ";
        }
    } else {
        dLength = 34;
        cout << dLength << endl;
        d[0] = 1;
        cout << 1 << " ";
        for (int i = 0; i <= 32; ++i) {
            d[i + 1] = static_cast<long>(pow(2, i));
            cout << d[i + 1] << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
        string ans;
        for (int j = dLength - 1; j >= 0; --j) {
            long x = abs(X[i]), y = abs(Y[i]);
            if (x == max(x, y)) {
                if (X[i] < 0) {
                    ans += 'L';
                    X[i] += d[j];
                } else {
                    ans += 'R';
                    X[i] -= d[j];
                }
            } else {
                if (Y[i] < 0) {
                    ans += 'D';
                    Y[i] += d[j];
                } else {
                    ans += 'U';
                    Y[i] -= d[j];
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}
