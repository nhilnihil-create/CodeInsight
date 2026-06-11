#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int h[1000000];
int dp[1000000];
int k,n;


int cost(int x){

      if(x==n-1)
        return 0;
      if(dp[x]!=-1)
        return dp[x];
      int c=abs(h[x+1]-h[x])+cost(x+1);
      for(int i=2;i<=k;i++){
      if(x+i>=n)
        break;

        c= min(c,abs(h[x+i]-h[x])+cost(x+i));
      }
        return  dp[x]=c;

    }


  int main(){


      cin>>n;
      cin>>k;


      for(int i=0;i<n;i++)
        cin>>h[i];


    memset(dp,-1,sizeof(dp));
    cout<<cost(0)<<endl;










  }












