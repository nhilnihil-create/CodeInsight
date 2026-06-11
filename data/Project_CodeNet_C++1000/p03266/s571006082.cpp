#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    ll n, k;
    cin >> n >> k;

    ll shou = n / k;
    ll amar = n % k; 

    ll ans = 0;
    for(int a=1; a<=n; a++){
        int a_mod_k = a % k;
        if((2 * a_mod_k) % k == 0){
            if(a_mod_k != 0 && a_mod_k <= amar){
                ans += pow(shou+1, 2);
            }
            else{
                ans += pow(shou, 2);
            }
        }
    }

    cout << ans << endl;
    return 0;
}