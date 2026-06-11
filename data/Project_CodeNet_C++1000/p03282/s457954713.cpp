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
    string s;
    cin >> s;
    ll k;
    cin >> k;

    ll total = 0;
    for (int i = 0; i < s.length(); i++) {
        int num = s[i] - '0';
        if (num == 1) {
            k -= 1;
        } else {
            k = 0;
        }
        if (0 >= k) {
            cout << num << endl;
            break;
        }
    }

    return 0;
}