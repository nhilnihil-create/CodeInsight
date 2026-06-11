#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n=s.size();

    int idx = 0;
    int ans = 0;
    int cnt = 0;
    while(idx<n) {
        if(s[idx]=='A'){
            cnt++;
        }
        else if(s[idx]=='B' && s[idx+1]=='C'){
            ans+=cnt;
            idx++;
        }
        else cnt=0;
        idx++;
    }
    cout << ans << "\n";

    return 0;
}