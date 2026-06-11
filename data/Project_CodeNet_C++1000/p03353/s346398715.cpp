#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    string s;
    ll k;
    cin>>s>>k;
    map<string,ll> mp;
    for(ll i=1;i<=min(k,(ll)s.size());i++){
        rep(j,s.size()-i+1){
            mp[s.substr(j,i)]++;
        }
    }
    ll cnt=0;
    for(auto x:mp){
        cnt++;
        if(cnt==k){
            cout<<x.first<<endl;
            break;
        }
    }
    return 0;
}