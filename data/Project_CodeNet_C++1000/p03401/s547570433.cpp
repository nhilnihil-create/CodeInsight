#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
#define ll long long int

int main(){
    int n;
    cin>>n;
    vector<int> v(n+2);
    v[0]=0;
    rep(i, n) cin>>v[i+1];
    v[n+1]=0;
    vector<int> diff(n+1);
    rep(i, n+1){
        diff[i]=abs(v[i+1]-v[i]);
    }
    ll sum=accumulate(diff.begin(), diff.end(), 0LL);
    for(int i=1;i<=n;i++){
        ll ans=sum-diff[i-1]-diff[i]+(ll)abs(v[i+1]-v[i-1]);
        cout<<ans<<endl;
    }
    return 0;
    
}