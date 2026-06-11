#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fr first
#define sc second
const int mod = 1e9+7;
const int N = 1e6+6;
ll a[N][3];
ll val(int id,int msk){
    ll ret = 0;
    for(int i=0;i<3;i++){
        if(msk&(1<<i))ret+=a[id][i];
        else ret-=a[id][i];
    }
    return ret;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    ll ans = 0;
    for(int j=0;j<8;j++){
        vector<ll>v;
        for(int i=0;i<n;i++){
            v.pb(val(i,j));
        }
        sort(v.rbegin(),v.rend());
        ll trt = 0;
        for(int i=0;i<m;i++)trt+=v[i];
        ans = max(ans,trt);
    }
    cout<<ans<<endl;
}
