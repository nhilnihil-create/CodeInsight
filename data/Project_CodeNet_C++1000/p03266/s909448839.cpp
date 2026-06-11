#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,K;
    cin >> N >> K;
    ll ans;
    if (K % 2 == 1){
        ll count = 0;
        for (ll i = 1; i <= N; i++){
            if (i % K == 0){
                count++;
            }
        }
        ans = count * count * count;
    }
    else if (K % 2 == 0){
        ll count_1 = 0;
        ll count_2 = 0;
        for (ll i = 1; i <= N; i++){
            if (i % K == 0){
                count_1++;
            }
            else if (i % K == (K / 2)){
                count_2++;
            }
        }
        ans = count_1 * count_1 * count_1 + count_2 * count_2 * count_2;
    }
    cout << ans << endl;
}
