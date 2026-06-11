#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, K;
    cin >> N >> K;
    ll ans = 0;
    for (int b=K+1; b<=N; b++) {
        int p = N / b;
        int r = N % b;
        ans += p * (b - K);
        ans += max(0, r + 1 - K); 
        if (K == 0) ans--;
    }
    cout << ans << endl;
    return 0;
}