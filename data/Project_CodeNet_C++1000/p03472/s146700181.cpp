#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n), b(n);

    ll max_a = 0;
    for(ll i=0; i<n; i++){
        cin >> a[i] >> b[i];
        if(a[i] > max_a){
            max_a = a[i];
        }
    }
    priority_queue<ll> thrw;
    for(ll i=0; i<n; i++){
        if(b[i] >= max_a) thrw.push(b[i]);
    }

    ll ttl = 0;
    ll cnt = 0;
    while(ttl < h){
        if(thrw.empty()){
            ttl += max_a;
            cnt++;
        }
        else{
            ttl += thrw.top();
            thrw.pop();
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}