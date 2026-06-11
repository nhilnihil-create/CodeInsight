#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,a[100005],g1[100005],g2[100005],ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    g1[0]=a[0];
    g2[n-1]=a[n-1];
    for(int i=1;i<n;i++){
        g1[i]=gcd(a[i],g1[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        g2[i]=gcd(a[i],g2[i+1]);
    }
    for(int i=0;i<n;i++){
        ans=max(ans,gcd(g2[i+1],g1[i-1]));
    }
    cout<<ans<<endl;
    return(0);
}