#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(i=a;i<n;i++)
#define test(a) cout << "*" << a << endl
#define ll long long
int main (){
  int i,j,k;
  int iMin;
  ll N,K;
  ll x[100000];
  ll xMin = 100000000;
  ll dist;
  ll distMin=10000000000000000;
  ll count=0;
  //ll xMax = 0;
  
  cin >> N >> K;
  rep(i,0,N){
    cin >> x[i];
    /*if(x[i]<=xMin){
      xMin = x[i];
    }*/
    /*else if(xMax<=x[i]){
      xMax = x[i];
    }*/
    if(0<=x[i] && x[i]<=xMin){/*注意：全て「ー」にある例外も考慮すべし*/
      xMin = x[i];
      iMin = i;
      //test(iMin);
    }
  }
  if(xMin == 100000000){/*これか？！*/
    iMin = N-1;
  }
  //test(xMin);
  //test(xMax);
  
  while(K+1>count && 0<=iMin){
    if(N-1 < iMin+(K-1)){
        iMin -= 1;
        count++;
        continue; 
    }    
    if(x[iMin+(K-1)]*x[iMin]>0){
      dist = max(abs(x[iMin+(K-1)]),abs(x[iMin]));
    }
    else{
      if( abs(x[iMin]) < abs(x[iMin+(K-1)]) ){
        dist = x[iMin+(K-1)] - x[iMin] + abs(x[iMin]);
      }
      else{
        dist = x[iMin+(K-1)] - x[iMin] + abs(x[iMin+(K-1)]);
      }      
    }
    if(dist<distMin){
      distMin = dist;
      //test(iMin);
    }    
    iMin -= 1;
    count++; 
  }
  
  cout << distMin << endl;
  
 

}