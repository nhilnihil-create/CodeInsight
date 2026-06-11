#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(i=a;i<=n;i++)
#define ll long long
int main(){
  ll i,j;
  ll N,K;
  ll countMod[200001];
  ll sum = 0;
    
  cin >> N >> K ;
  rep(i,0,K-1)
   countMod[i] = 0;
  
  rep(i,1,N){
    if(2*i%K == 0)
      countMod[i%K] += 1;
  }
  rep(i,0,K-1)
    sum += pow(countMod[i],3);
 
  cout << sum << endl; 
}