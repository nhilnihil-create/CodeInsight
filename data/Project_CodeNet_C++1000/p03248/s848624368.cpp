#include <bits/stdc++.h>

using namespace std;
// #define int long long
mt19937 rnd(time(0));
typedef long long ll;
typedef long double ld;

// #define _GLIBCXX_DEBUG
#define f first
#define s second
#define pb push_back
#define pii pair<int, int> 
#define vi vector<int>

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    bool ok = 1;
    for (int i = 0; i < n - 1; ++i) 
        ok &= (s[i] == s[n - 2 - i]);
    if (s[0] == '0' || s[n - 1] == '1' || !ok) {
        cout << -1 << endl;
        exit(0);
    }
    int now = 2;
    cout << 1 << ' ' << 2 << endl;
    for (int i = 1; i < n - 1; ++i) {
        if (s[i] == '1') {
            if (now != 0)
                cout << now << ' ' << i + 2 << endl;
            now = i + 2;
        } else {
            cout << now << ' ' << i + 2 << endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    while(t--){
        solve();
    }
    
    return 0;
}
