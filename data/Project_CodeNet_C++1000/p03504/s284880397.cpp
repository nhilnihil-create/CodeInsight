#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005];

int main(){
    ll n, c;
    cin >> n >> c;
    for(ll i=0;i<n;i++){
        ll s,t,cc;
        cin >> s >> t >> cc;
        a[s]++;
        a[t+1]--;
    }
    ll memo=0;
    for(ll i=1;i<=100000;i++){
        a[i]=a[i - 1]+a[i];
        memo=max(memo,a[i]);
    }
    memo=min(memo,c);
    cout << memo << endl;
}
