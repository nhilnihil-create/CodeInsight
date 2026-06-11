#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N;
    cin >> N;
    // 商がA、余りもA
    // → N = A*m + Aの形(A<m)
    ll ans = 0;
    for(ll i=1;i*i<=N;i++){
        if((N-i)/i > i && (N-i)%i == 0){
            ans += (N-i)/i; 
        }
    }
    cout << ans << endl;
    return 0;
}