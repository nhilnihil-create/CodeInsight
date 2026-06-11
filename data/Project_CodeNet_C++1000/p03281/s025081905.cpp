#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);

bool divisor(int x) {
    int cnt = 0;
    int tmp = 1;
    while (tmp * tmp <= x) {
        if (x % tmp == 0) {
            if (tmp * tmp != x)
                cnt += 2;
            else
                cnt++;
        }
        tmp++;
    }
    if (cnt == 8)
        return true;
    else
        return false;
}

int main() {
    int N;
    cin >> N;
    int ans = 0;
    rep2(i, 1, N + 1) {
        if ((i % 2) && divisor(i)) ans++;
    }
    cout << ans << endl;
}