#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n;
    string s;
    cin>>n>>s;
    map<pair<string,string>,ll> mp1,mp2;
    for(int bit=0;bit<(1<<n);bit++){
        string r1,r2,b1,b2;
        for(int i=0;i<n;i++){
            if(bit&(1<<i)){
                r1 += s[i];
                r2 += s[n+i];
            }
            else{
                b1 += s[i];
                b2 += s[n+i];
            }
        }
        reverse(b1.begin(),b1.end());
        reverse(b2.begin(),b2.end());
        mp1[make_pair(r1,b1)]++;
        mp2[make_pair(b2,r2)]++;
    }
    ll ans = 0;
    for(auto i:mp1){
        ans += i.second * mp2[make_pair(i.first.first,i.first.second)];
    }
    cout << ans << endl;
}