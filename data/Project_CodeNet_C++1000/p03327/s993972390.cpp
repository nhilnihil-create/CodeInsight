#include<bits/stdc++.h>
using ll = long long;
const ll INF_LL = 1000000000000;
#define fir first
#define sec second
using namespace std;
/*

int main()
{
    ll n,q,s,t;
    cin >> n >> q >> s >> t;
    vector<ll> high(n + 1);
    vector<ll> L(q),R(q),X(q);
    for(int i = 0; i <= n; i++)cin >> high[i];
    for(int i = 0; i < q; i++)cin >> L[i] >> R[i] >> X[i];

    ll cur = 0;
    for(int i = 1; i <= n; i++){
        if(high[i] > high[i - 1]){
            cur -= s * (high[i] - high[i - 1]);
        }else{
            cur += t * (high[i - 1] - high[i]);
        }
    }
    
    for(int i = 0; i < q; i++)
    {
        ll l = L[i], r = R[i], x = X[i];
        ll ch = 0;
        ch = (x >= 0 ? s : t) * x;
        if(r == n)continue;



        cout << cur << endl;
    }

}
*/

int main()
{
    int n;
    cin >> n;
    if(n < 1000)cout << "ABC" << endl;
    else        cout << "ABD" << endl;
}
