#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    string s; int w; cin >> s >> w;string ans;
    for(int i=0;i<s.size();i+=w) {
        ans += s[i];
    }
    cout << ans;
}