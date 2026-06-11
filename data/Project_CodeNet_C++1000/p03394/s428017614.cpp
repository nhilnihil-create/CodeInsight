#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
signed main() {
    int N;
    cin >> N;
    if(N == 3) {
        cout << 2 << ' ' << 3 << ' ' << 25 << endl;
    } else {
        vector<int> Ans;
        Ans.push_back(2);
        Ans.push_back(4);
        Ans.push_back(3);
        Ans.push_back(9);
        N -= 4;
        int n = min((int)2499, N / 2);
        N -= n * 2;
        int m = min((int)4999, N / 2);
        N -= m * 2;
        int k = N;
        //cout << n << ':' << m << ':' << k << endl;
        rep(i, 2 * n) {
            Ans.push_back(15 + i * 6);
        }
        rep(i, m) {
            Ans.push_back(8 + i * 6);
            Ans.push_back(10 + i * 6);
        }
        rep(i, k) {
            Ans.push_back(6 * (i + 1));
        }
        sort(all(Ans));
        for(auto x : Ans) cout << x << ' ';
        cout << endl;
    }
}
