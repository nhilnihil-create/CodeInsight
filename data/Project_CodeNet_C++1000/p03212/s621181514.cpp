#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll u[]={3,5,7};

bool isOK(ll x){
    bool t=0,f=0,s=0;
    while(x>0){
        if(x%10==3) t=1;
        if(x%10==5) f=1;
        if(x%10==7) s=1;
        x/=10;
    }
    if(t&&f&&s) return 1;
    else return 0;
}

void dfs(ll n,ll keta,vector<ll> &vec){
    if(keta==10) return;
    vec.push_back(n);
    for(ll i=0;i<3;i++){
        dfs(n*10+u[i],keta+1,vec);
    }
}

int main() {
    ll n;
    cin >> n;
    vector<ll>vec,num;
    dfs(3,1,vec);
    dfs(5,1,vec);
    dfs(7,1,vec);
    for(ll x:vec){
        if(isOK(x)) num.push_back(x);
    }
    ll ans=0;
    for(ll x:num){
        if(x>n) continue;
        ans++;
    }
    cout << ans << endl;
}