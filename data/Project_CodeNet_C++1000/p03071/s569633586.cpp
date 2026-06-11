#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    rep(i,2) {
        if(a>b) { ans += a; a--;}
        else { ans += b; b--;} 
    }
    cout << ans << endl;
    return 0;
}