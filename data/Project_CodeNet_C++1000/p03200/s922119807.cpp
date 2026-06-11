#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
 
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
typedef long long ll;
typedef unsigned long ul;
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // input
    string S;
    cin >> S;
    
    // calculation
    ll ans = 0, cnt = 0;
    ll len = (ll)S.length();
    REP(i, len) {
        if (S[i] == 'B') {
            cnt++;
        } else {
            ans += cnt;
        }
    }
  
    cout << ans << "\n";
    
    return 0;
}