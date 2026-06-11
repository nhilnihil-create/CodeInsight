#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { return (a%b == 0) ? b : gcd(b, a%b); }
inline int fac(int n) { return (n==0) ? 1 : n * fac(n - 1); }

int main() {
    int c[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }

    int b[3];
    int a[3];
    for (int i = 0; i < 3; i++) {
        b[i] = c[0][i];
    }

    a[1] = c[1][0] - c[0][0];
    a[2] = c[2][0] - c[0][0];
    for (int i = 1; i < 3; i++)
    {
        if (a[1] != c[1][i] - c[0][i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = 1; i < 3; i++)
    {
        if (a[2] != c[2][i] - c[0][i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
