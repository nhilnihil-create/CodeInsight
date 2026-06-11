#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    string s, S;
    cin >> s;
    int N = s.size();
    s += '.';
    for(int i = 0; i < N; i++) {
        if(s[i] == 'B' && s[i + 1] == 'C') {
            S += 'D';
            i++;
        } else
            S += s[i];
    }
    N = S.size();
    ll A = 0, ans = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'A')
            A++;
        else if(S[i] == 'D')
            ans += A;
        else
            A = 0;
    }
    cout << ans << "\n";
    return 0;
}