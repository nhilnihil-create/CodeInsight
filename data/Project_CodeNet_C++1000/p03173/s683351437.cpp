// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
int mod =1e9+7;
int main(){
int n;
cin >> n;
vector<long long int>A(n);
for(int i=0;i<n;++i)
    cin >> A[i];
vector<vector<long long int> >dp(n,vector<long long int>(n,1e18+8));
int L,R;
for(L=n-1;L>=0;--L){
    for(R=L;R<n;++R){
        if(L==R){
            dp[L][R]=0;
        }else{
            long long int s=0;
            for(int i=L;i<=R;++i)
                s+=A[i];
        // dp[L][R]=1e18+5;
           for(int i=L;i<R;++i){
            dp[L][R]=min(dp[L][R],dp[L][i]+dp[i+1][R]+s);

           }

        }

    }
}
cout << dp[0][n-1]<<endl;
return 0;



}
