#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, b = 0, a = 0, ba=0;
    cin >> n;
    int ans = 0;
    rep(i,n) {
        string s;
        cin >> s;
        for(int i = 0; i < s.size()-1; ++i) {
            if(s[i]=='A' && s[i+1]=='B') ans++;
        }
        if(s[0]=='B' && s[s.size()-1]=='A') ba++;
        else if(s[s.size()-1]=='A') a++;
        else if(s[0]=='B') b++; 
    }
    ans += min(a+ba, b+ba);
    if(a==0 && b == 0 && ba > 0) ans--;
    cout << ans << endl;
    return 0;
}