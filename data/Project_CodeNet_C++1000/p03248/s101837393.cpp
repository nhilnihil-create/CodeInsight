#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n;
char s[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s + 1;
    n = strlen(s + 1);
    if(s[1] == '0' || s[n] == '1') {cout << -1; return 0;}
    for(int i = 1; i < n; i++) if(s[i] != s[n - i]) {
        cout << -1; return 0;
    }
    s[n] = '1';
    int rt = 1;
    for(int i = 2; i <= n; i++) if(s[i] == '1') {
        cout << i << ' ' << rt << '\n';
        for(int j = rt + 1; j < i; j++) cout << i << ' ' << j << '\n';
        rt = i;
    }
    return 0;
}
