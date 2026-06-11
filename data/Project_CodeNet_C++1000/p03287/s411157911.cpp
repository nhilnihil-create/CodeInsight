#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int n, m;
    cin >> n >> m;
    vector<ll> A(n);
    vector<ll> CulA(n+1);
    map<ll, ll> mp;
    CulA[0] = 0;
    mp[0] = 1;
    ll ans = 0;
    for(int i=0; i<n; i++){
        cin >> A[i];
        CulA[i+1] = CulA[i] + A[i];
        ans += mp[CulA[i+1] % m];
        mp[CulA[i+1] % m]++;
    }
    cout << ans << endl;
    return 0;
}