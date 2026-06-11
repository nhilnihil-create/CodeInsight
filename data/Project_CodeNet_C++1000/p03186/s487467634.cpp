#include <bits/stdc++.h>

using namespace std;
#define int long long
int MOD = 1000000007;

signed main(){
    int A,B,C;
    cin >> A >> B >> C;
    
    int ans = 0;
    if(A+B>=C) ans+= C;
    else ans+= A+B+1;
    
    ans += B;
    
    cout << ans << endl;
    return 0;
}
