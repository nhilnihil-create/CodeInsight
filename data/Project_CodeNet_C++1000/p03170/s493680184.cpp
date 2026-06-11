/* UserName - ankit_S
  author -Ankit kumar
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long 
const ll int MOD=1e9+7;

int main()
{
    FAST
    int n,k;
    cin>> n >> k;
    vector<int> stone(n);
    for(int i=0;i<n;i++){
    	cin>> stone[i];
   	}
    vector<bool>dp(k+1,false);
    dp[0]=true;
    for(int i=1;i<=k;i++ ){
        for(int j=0;j<n;j++){
            if(i>=stone[j]){
                if(i==stone[j])dp[i]=true;
                else {
                    dp[i]=dp[i]|(!dp[i-stone[j]]);
                }
            }
        }
       
    }
    // for(auto i:dp)cout<<i<<" ";
    // cout<<endl;
    if(dp[k])cout<<"First"<<endl;
    else cout<<"Second"<<endl;   
 
    return 0;
}
