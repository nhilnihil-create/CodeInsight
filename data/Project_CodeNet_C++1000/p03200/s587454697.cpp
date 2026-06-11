#include<bits/stdc++.h>

#define loop(i, n) for(int i = 0; i < n; i++)
#define sloop(i, s, n) for (int i = s; i < n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    long long int count = 0, ans = 0;
    rloop(i, s.size()) {
        if(s[i] == 'W') count++;
        else ans += count;
    }
    cout << ans << endl;
    return 0;
}
