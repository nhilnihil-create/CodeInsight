#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;
// 11
int main() {
    string s;
    cin >> s;
    int zero = 0;
    int ichi = 0;
    rep(i,s.size()){
        if(s[i]=='1') ichi++;
        else zero++;
    }
    int ans = min(ichi, zero);
    cout << ans*2 << endl;
    return 0;
}