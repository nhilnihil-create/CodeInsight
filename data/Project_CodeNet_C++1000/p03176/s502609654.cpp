


#include <bits/stdc++.h>
using namespace std;
#define ll long long 


ll int solve(ll int h[],ll int a[],int n){

    ll dp[n];
    map<ll,ll> meaningful;
    dp[0]=a[0];
    meaningful[h[0]]=dp[0];
    ll ans=a[0];

    for(int i=1;i<n;i++){

        dp[i]=a[i];

        auto it=meaningful.lower_bound(h[i]+1);

        if(it!=meaningful.begin()){
            it--;
            dp[i]+=it->second;
        }
        meaningful[h[i]]=dp[i];

        it=meaningful.upper_bound(h[i]);

        while(it!=meaningful.end() && it->second<=dp[i]){
            auto temp=it;
            temp++;
            meaningful.erase(it);
            it=temp;

        }

        ans=max(ans,dp[i]);


    }

    return ans;

}


int main() {
   int n;
   cin>>n;
   ll int h[n],a[n];

   for(int i=0;i<n;i++){
       cin>>h[i];

   }

   for(int i=0;i<n;i++){
       cin>>a[i];
   }

   cout<<solve(h,a,n);


}
