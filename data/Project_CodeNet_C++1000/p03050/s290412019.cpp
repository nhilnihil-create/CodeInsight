#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    ll N; cin >> N;
    ll ans = 0;
    for(ll i = 1; i * i < N; i++){
        if(N % i == 0){
            ll m = N / i - 1;
            if(m > i){
                ans += m;
                //cout << N << " " << i << " " << m << endl;
            }
            
        }
    }
    cout << ans << endl;
    
}