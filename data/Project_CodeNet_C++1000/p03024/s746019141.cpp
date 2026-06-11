#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    string s;
    cin >> s;
    int cnt = 0, k = s.size();
    for(char c : s){
        if (c == 'o') cnt++;
    }
    cnt += 15 - k;
    puts((cnt >= 8 ? "YES" : "NO"));
}