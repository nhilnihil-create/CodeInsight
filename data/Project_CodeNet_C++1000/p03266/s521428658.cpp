#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    ll ans = 0; 
    for(int a = 1; a <= N; ++a){
        if((2*a)%K != 0) continue;
        int upper = (N+a)/K;
        int lower = (a+1+K-1)/K;
        int tmp = upper - lower;
        if(tmp < 0) continue;
        tmp++;
        ans += (ll) tmp*tmp;
    }
    cout << ans << endl;
    return 0;
}