#include<bits/stdc++.h>
using namespace std;

int main(){
      int n, k;
      cin>>n>>k;
      vector<int>a(n);
      for(int i=0; i<n; i++)
            cin>>a[i];

      vector<bool>dp(k+1, false);
      for(int i=1; i<=k; i++){
            for(int j=0; j<n; j++){
                  if(a[j]<=i){
                        if(dp[i-a[j]]==false)
                              dp[i]=true;
                  }
            }
      }
      if(dp[k]==true)cout<<"First\n";
      else cout<<"Second\n";
}