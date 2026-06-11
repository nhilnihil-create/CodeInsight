#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long INF = 1LL << 60;
using Graph = vector<vector<int>>;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

inline int gcd(int a, int b) { return (a % b == 0) ? b : gcd(b, a % b); }
inline int fac(int n) { return (n == 0) ? 1 : n * fac(n - 1); }

int count_matches(string a, string b) {
    bool alpha[27] = {};
    int cnt = 0;
    for (int i = 0; i < a.length(); i++)
    {
        int code = a[i] - 'a';
        if (alpha[code] == false && find(b.begin(), b.end(), a[i]) != b.end())
        {
            alpha[code] = true;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        string a = s.substr(0, i);
        string b = s.substr(i, s.size());
        int matches = count_matches(a, b);
        if (matches > max) {
            max = matches;
        }
    }

    cout << max << endl;
    return 0;
}