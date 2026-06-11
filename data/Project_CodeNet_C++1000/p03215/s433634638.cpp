#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,k;cin >> n >> k;
    vector<int> a(n);
    vector<ll> sum(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum[i+1]=sum[i]+a[i];
    }
    ll ans=0;
    vector<ll> c(40);
    c[0]=1;
    for(int i=1;i<40;i++){
        c[i]=c[i-1]*2;
    }
    for(int i=39;i>=0;i--){
        int cnt=0;
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n+1;k++){
                ll x=(ans+c[i])&(sum[k]-sum[j]);
                if(x==ans+c[i]){
                    cnt++;
                }
            }
        }
        if(cnt>=k){
            ans+=c[i];
        }
    }
    cout << ans << endl;
}