

//* dp[i] = 1; if Taro win
//*         0; otherwise

//* dp[i]=1; if dp[i-A[j]]==0 where j belongs to [0, n-1]
//*       0 otherwise

//* BASE CASE
//* dp[0]=0; If there are 0 stones in pile then Taro looses

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> A(n);
    for(int &x:A){
        cin>>x;
    }
    vector<int> dp(k+1);
    for(int i=1;i<=k;i++){
        bool doesExist=false;
        for(int j=0;j<n;j++){
            if(i-A[j]>=0){
                if(dp[i-A[j]]==0){
                    doesExist=true;
                    break;
                }
            }else{
                doesExist=false;
                break;
            }
        }
        if(doesExist){
            dp[i]=1;
        }
    }
    if(dp[k]){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }

}