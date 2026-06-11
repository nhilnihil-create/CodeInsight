#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long X, long long Y){
    ll cnt = 0;
    while(X <= Y){
        cnt++;
        X *= 2;
    }
    cout << cnt << endl;
    return;
}

int main(){
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    solve(X, Y);
    return 0;
}
