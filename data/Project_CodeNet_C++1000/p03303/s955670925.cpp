#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    string s;
    cin >> s;
    cin >> n;
    for(i=0;i<s.size();i+=n){
        cout << s[i];
    }
    cout << endl;
    return 0;
}