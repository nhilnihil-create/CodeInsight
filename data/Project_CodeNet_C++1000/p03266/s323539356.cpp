#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(i=a;i<=n;i++)
#define ll long long
int main(){
  ll i,j;
  ll N,K;
  ll countMod[200001];
  ll sum = 0;
  ll sumTmp;
  
  
  cin >> N >> K ;
  rep(i,0,K-1){
   countMod[i] = 0;
  }
  
  rep(i,1,N){
    if(2*i%K == 0){
      countMod[i%K] += 1;
      //cout << i << endl;
    }
  }
  rep(i,0,K-1){
    sumTmp = sum;
    sum += pow(countMod[i],3);
    
    if(sum != sumTmp){
      //cout << i << endl;
      //cout << sum << endl;
      //cout << "*" << endl;
    }
    
  }
  //cout << countMod[199606] << endl;
  //cout << pow(countMod[199607],3) << endl;
  //cout << countMod[199608] << endl;
  
  cout << sum << endl;
  
}