#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    int x;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }    

    vector<int> dp(k+1);
    dp[0]=0;
    for(int i=1;i<k+1;i++){
        for(int j=0;j<n;j++){
            if(i-nums[j] >=0 && (dp[i-nums[j]]==0)){
                dp[i]=1;
                break;
            }
        }
    }


    /*
    * Not so nice approach -> O(n^2) *

    for(int i=1;i<k+1;i++){
        for(int j=i-1;j>=0;j--){
            if(dp[j]==0 && cnt.count(i-j)){
                dp[i]=1;
                break;
            }
        }
    }

    */

    if(dp[k]){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
}