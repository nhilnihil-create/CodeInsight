#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;


int main(){
    long double ans=0;
    long double n,k;
    cin>>n>>k;
    if(n>k){
        ans = (n-k+1)/n;
        for(int i=1;i<k;i++){            
            int p2 = ceil(log2(k/i));  
            ans += (1.0/n)*(long double)pow(0.5,p2);
        }
    }
    else{
        for(int i=1;i<=n;i++){
            int p2 = ceil(log2(k/i));            
            ans += (1.0/n)*(long double)pow(0.5,p2);
            // cout<<ans<<' ';
        }
    }
    cout<<fixed<<setprecision(20)<<ans;

}