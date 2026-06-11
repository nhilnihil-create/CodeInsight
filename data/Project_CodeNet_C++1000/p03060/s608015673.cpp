#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(y==0)return x;
    return gcd(y,x%y);
}
ll LCM(ll a, ll b){
    return a/gcd(a,b)*b;
}

int main(void)
{
    int n;
    cin>>n;
    vector<int> v(n),c(n);
    int v_sum=0,c_sum=0;
    rep(i,0,n){ cin>>v[i]; v_sum+=v[i];}
    rep(i,0,n){ cin>>c[i]; c_sum+=c[i];}

    int ans=0;
    rep(i,0,n){
        if(v[i]-c[i]>0)ans+=v[i]-c[i];
    }
    cout<<ans<<endl;
     
    return 0;
}