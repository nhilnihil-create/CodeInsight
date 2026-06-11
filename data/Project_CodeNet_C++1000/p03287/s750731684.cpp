#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n,m;cin>>n>>m;
    ll a[100010];
    map<ll,ll> mp;
    rep(i,0,n){
        cin>>a[i];
        if(i==0){mp[a[i]%m]++;continue;}
        a[i]+=a[i-1];
        mp[a[i]%m]++;
    }
    ll an=0;
    for(auto i:mp){
        ll b=i.first,cn=i.second;
        if(b==0){
            if(cn!=0)an+=(cn+1)*cn/2;
        }
        else{
            an+=cn*(cn-1)/2;
        }
    }
    cout<<an<<endl;
}

    







