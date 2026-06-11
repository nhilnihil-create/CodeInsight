#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int main(){
    ll N;
    cin >> N;
    ll po[N];
    for(ll i = 0; i < N; i++) cin >> po[i];
    ll ans = 0;
    if(po[0]){
        cout << -1 << endl;
        return 0;
    }
    for(ll i = 1; i < N; i++){
        if(po[i - 1] + 1 < po[i] || i < po[i]){
            cout << -1 << endl;
            return 0;
        }else if(po[i - 1] + 1 == po[i]){
            ans++;
        }else if(po[i] <= po[i - 1]){
            ans += po[i];
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}