
#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void){
    int n;
    cin>>n;
    map<ll,ll> mp;
    rep(i,0,n){
        ll a;
        cin>>a;
        mp[a]++;
    }

    ll ans=0;
    for(auto i:mp){
        if(i.second<i.first)ans+=i.second;
        else if(i.second>i.first)ans+=i.second-i.first;
    }
    cout<<ans<<endl;

    return 0;
}

