#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;cin>>n>>k;
    vector<long long>a(n),b(40,0),c(40,1),d(40,0);
    for(int i=0;i<n;++i){
        cin>>a[i];
        int cnt=0;
        while(a[i]>0){
            if(a[i]%2==1)b[cnt]++;
            a[i]/=2;
            cnt++;
        }
    }
    long long m=k+1;
    int co=0;
    while(m>0){
        if(m%2==1)d[co]++;
        co++;
        m/=2;
    }
    for(int i=1;i<40;++i)c[i]=c[i-1]*2;
    long long ans=0;
    for(int i=0;i<40;++i){
        if(d[i]==1){
            long long sum=0;
            for(int j=0;j<i;++j){
                sum+=c[j]*max(b[j],n-b[j]);
            }
            sum+=c[i]*b[i];
            for(int j=i+1;j<40;++j){
                if(d[j]==0)sum+=c[j]*b[j];
                else sum+=c[j]*(n-b[j]);
            }
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}
