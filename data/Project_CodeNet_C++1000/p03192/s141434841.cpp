#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    string n;
    cin >> n;
    ll ans=0;
    for(ll i=0;i<4;i++){
        if(n[i]=='2'){
            ans++;
        }
    }
    cout << ans << endl;
}