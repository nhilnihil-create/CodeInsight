#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s, t;
    cin >> s >> t;
    if(s[0] == t[2] && s[1] == t[1] && s[2] == t[0]) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}