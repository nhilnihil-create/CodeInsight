#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string s; cin >> s;
    int n = s.size();

    int ans = 0;
    int l = 0, r = n-1;
    while(l < r){
        if(s[l] == s[r]){
            l++;
            r--;
        } else if(s[l] == 'x'){
            l++;
            ans++;
        } else if(s[r] == 'x'){
            r--;
            ans++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}