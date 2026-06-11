#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {

    // ここから入力
    
    ll a,b,ans = 0;
    cin >> a >> b;
    
    while(a <= b){
        ans++;
        a *= 2;
    }
    
    cout << ans << endl;

}
