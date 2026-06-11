#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N,M;
    cin >> N >> M;
    ll ans = 1;
    for(ll i = M / N; i > 1; i--){
        if((M - i * N) % i == 0){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}



