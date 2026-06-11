#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    vector<ll> v;
    if(s[0]=='0') v.push_back(0);
    int l=0;
    while(l<n){
        char t=s[l];
        int c=0;
        while(s[l]==t){
            l++;
            c++;
        }
        v.push_back(c);
    }
    if(s[n-1]=='0') v.push_back(0);
    int m=v.size();
    ll sum[m+1]={};
    for(int i=0;i<m;i++){
        sum[i+1]=sum[i]+v[i];
    }
    if((m-1)/2<k){
        cout<<sum[m]<<endl;
        return 0;
    }

    ll ans=0;
    for(int i=2*k+1;i<=m;i+=2){
        ans=max(ans,sum[i]-sum[i-2*k-1]);
    }
    cout<<ans<<endl;
    return 0;
}
