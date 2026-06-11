#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n),sum(n+1,0);
    int i;
    for(i=0;i<n;i++){
        cin >> a.at(i);
        sum.at(i+1)=sum.at(i)+a.at(i);
    }
    //for(i=0;i<n+1;i++)cout << sum.at(i)<<endl;
    //cout << endl;
    ll ans = 0;
    map<ll,ll> mp;
    for(i=0;i<n+1;i++){
        ans += mp[sum.at(i)];
        mp[sum.at(i)]++;
    }

    cout << ans << endl;
    return 0;
}