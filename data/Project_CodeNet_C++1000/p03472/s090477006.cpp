#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N, H;
    cin >> N >> H;
    vector<pair<ll,ll>> ba(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> ba.at(i).second >> ba.at(i).first;
    }
    
    sort(ba.begin(), ba.end(), greater<pair<ll,ll>> ());

    ll maxa = zero;
    for (ll i = 0; i < N; i++)
    {
        maxa = max(ba.at(i).second , maxa);
    }
    
    ll tmp, cnt;
    cnt = zero;
    for (ll i = 0; i < N; i++)
    {
        tmp = ba.at(i).first;
        if(tmp >= maxa){
            H -= tmp; cnt++;
        }
        else{
            break;
        }
        if(H<=0) break;
    }
    if(H > 0) cnt += 1 + (H-1)/maxa;
    printf("%lld\n", cnt);
    


}
