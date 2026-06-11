#include <bits/stdc++.h>
using namespace std;
#define int long long

 //bool dp[2][4000001];

signed main(){
    int n;
    cin >>n;
    int a[n],sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    bitset<4000001> dp2;
    dp2.set(0);
   
    //for(int j=0;j<=sum/2;j++)dp[0][j]=false;
    //dp[0][0]=true;
    //dp[0][a[0]]=true;
    //for(int i=0;i<n;i++)for(int j=0;j<=sum/2 ;j++)cerr <<dp[i][j]<<' ';
   // cerr <<endl;
    //for(int i=1;i<n;i++){
    //    for(int j=0;j<a[i];j++)dp[i%2][j]=dp[(i+1)%2][j];
    //    for(int j=a[i];j<=sum/2 ;j++)dp[i%2][j]=(dp[(i+1)%2][j-a[i]]||dp[(i+1)%2][j]);
    //}
        
    //int k=sum/2;
  //  for(int i=0;i<n;i++)for(int j=0;j<=sum/2 ;j++)cerr <<dp[i][j]<<' ';
    //cerr <<sum<<' ';
    //while(k>=0&&dp[(n-1)%2][k]==0)k--;
    //cerr <<k<<' ';
    //cout << sum-k;
    for(int i=0;i<n;i++){
        dp2 |= (dp2<<a[i]);
    }
    int k=(sum+1)/2;
    while(!dp2[k])k++;
    cout <<k;
    

    return 0;
}