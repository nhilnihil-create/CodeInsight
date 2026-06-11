#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string s; cin >> s;
    int n = s.size();
    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n-2; i++){
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
            ans += cnt + 1;
            s[i+2] = 'A';
            i++;
        } else if(s[i] == 'A'){
            cnt++;
        } else {
            cnt = 0;
        }
    }

    cout << ans << endl;

    return 0;
}