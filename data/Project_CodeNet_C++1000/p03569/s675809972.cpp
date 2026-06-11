#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int l = 0;
    int r = n-1;
    int ans = 0;
    while (r>l){
        if (s[l] == s[r]){
            l++;r--;
        } else if (s[l] == 'x'){
            l++;ans++;
        } else if (s[r] == 'x'){
            r--;ans++;
        } else {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << ans << "\n";
}