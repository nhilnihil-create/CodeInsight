#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { if (a%b == 0) { return b; } else { return gcd(b, a%b); } }

int main() {
    int n;
    cin >> n;
    int t[n+1], x[n+1], y[n+1];
    t[0] = x[0] = y[0] = 0;
    bool judge = true;
    for (int i = 1; i < n + 1; i++) {
        cin >> t[i] >> x[i] >> y[i];
        int t_dis = (t[i] - t[i - 1]) - ( abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) );
        judge = judge ? (t_dis % 2 == 0) && (t_dis >= 0) : false;
    }

    cout << (judge ? "Yes" : "No") << endl;
    return 0;
}