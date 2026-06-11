#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    int k;cin>>k;
    ll ans=0;
    if(k%2==0){
        ans=k/2*k/2;
    }else{
        ans=k/2*(k/2+1);
    }
    cout<<ans<<endl;
}