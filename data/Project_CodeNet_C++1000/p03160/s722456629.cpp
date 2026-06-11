#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int h[1000000];
int dp[1000000];

int cost(int x,int y){

      if(x==y)
        return 0;
      if(dp[x]!=-1)
        return dp[x];
      int c=abs(h[x]-h[x+1])+cost(x+1,y);
      if(x+2<=y)
        c= min(c,(cost(x+2,y)+abs(h[x+2]-h[x])));

        return  dp[x]=c;

    }


  int main(){

      int n;
      cin>>n;


      for(int i=1;i<=n;i++)
        cin>>h[i];


    memset(dp,-1,sizeof(dp));
    cout<<cost(1,n)<<endl;










  }












