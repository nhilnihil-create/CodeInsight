#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007



int main(){
    ll n,k;
    cin>>n>>k;

    vector<ll> t(n+1);

    ll v;
    for(int i=0;i<n;i++){
        cin>>v;
        t.at(v)++;
    }

    ll co=0;
    for(int i=0;i<n+1;i++){
        if(t.at(i)==0){
            t.at(i)=200001;
        }else{
            co++;
        }
    }

    sort(t.begin(),t.end());

    ll ans=0;
    for(int i=0;i<(co-k);i++){
        ans += t.at(i);
    }

    cout<<ans<<endl;
}

