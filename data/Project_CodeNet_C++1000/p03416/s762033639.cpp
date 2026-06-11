#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b;
    cin >> a >> b;

    int ans=0;
    for (int i=a; i<=b; i++) {
        string sbuff=to_string(i);
        
        if (sbuff[0]==sbuff[4] && sbuff[1]==sbuff[3]) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}