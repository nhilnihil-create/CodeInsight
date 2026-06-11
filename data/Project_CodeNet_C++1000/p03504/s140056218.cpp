#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,c;
ll a[100005];
ll b[100005];

int main(){
    cin >> n >> c;
    for(ll i=0;i<n;i++){
        ll s,t,cc;
        cin >> s >> t >> cc;
        a[s]++;
        a[t+1]--;
    }
    ll memo=0;
    for(ll i=0;i<100004;i++){
        b[i+1]=b[i]+a[i];
        memo=max(memo,b[i+1]);
    }
    memo=min(memo,c);
    cout << memo << endl;
}
