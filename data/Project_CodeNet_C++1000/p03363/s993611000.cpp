#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll X;
    cin >> X;
    vector<ll> N(X,0);
    map<ll,ll> cnt;
    vector<ll> sum(X + 1,0);

    cnt[0]++;

    for(int i = 0; i < X; i++){
        cin >> N[i];
        sum[i + 1] = sum[i] + N[i];
        cnt[sum[i + 1]]++;
    } 
    
    ll ans = 0;

    for(auto it:cnt){
        ans += (it.second) * (it.second - 1) / 2;
    }

    cout << ans << endl;

}



