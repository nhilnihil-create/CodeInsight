#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
 
int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a; i <= b; ++i) {
        stringstream ss;
        ss<<i;
        string s;
        ss>>s;
        string r = s;
        reverse(all(r));
        if(s==r) ans++;
    }
    cout << ans << endl;
    return 0;
}