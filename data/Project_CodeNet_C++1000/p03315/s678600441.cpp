#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    for(int i = 0; i < 4; i++)
        if(S[i] == '+')
            ans++;
        else
            ans--;
    cout << ans << "\n";
    return 0;
}