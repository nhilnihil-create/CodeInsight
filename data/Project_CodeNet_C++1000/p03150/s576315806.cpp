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
    string s;
    cin >> s;

    const string keyence = "keyence";

    int start = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != keyence[i]) {
            start = i;
            break;
        }
    }
    
    if (start == -1) {
        cout << "YES" << endl;
        return 0;
    }

    int length = keyence.length() - start;
    if (s.substr(s.length() - length, length) == keyence.substr(start, length))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

        return 0;
}
