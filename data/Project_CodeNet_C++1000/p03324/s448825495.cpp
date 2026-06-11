#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll d,n; cin>>d>>n;
    map<ll,ll> mp;
    rep(i,n){
        if(d==0){
            if(n!=100) mp[i]=i+1;
            else mp[i]=101;
        }else if(d==1){
            if(n!=100) mp[i]=100*(i+1);
            else mp[i]=100*101;
        }else{
            if(n!=100) mp[i]=10000*(i+1);
            else mp[i]=10000*101;
        }
    }
    cout<<mp[n-1]<<endl;
    return 0;
}