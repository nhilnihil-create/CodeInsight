#include <bits/stdc++.h>
using namespace std;


void solve(long long A, long long B, long long C){
    vector<long long> d(3, 0);
    d[0] = max(A, max(B, C)) - A;
    d[1] = max(A, max(B, C)) - B;
    d[2] = max(A, max(B, C)) - C;
    sort(d.begin(), d.end());
    //for(auto i : d) cout << i << endl;
    long long ans = 0;
    ans += d[1];
    d[2] -= d[1];
    d[1] -= d[1];
    //for(auto i : d) cout << i << endl;
    if(d[2] % 2 == 0) ans += d[2]/2;
    else ans += d[2]/2 + 2;
    cout << ans << endl;
    return;
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    long long C;
    scanf("%lld",&C);
    solve(A, B, C);
    return 0;
}
