#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll n,m,i;
  vector<ll> x;
  cin >> n >> m;
  for(i=1;i*i<=m;i++){
    if(m%i==0){
      x.push_back(i);
      if(i!=(m/i)){
        x.push_back(m/i);
      }
    }
  }
  ll ans=0;
  for(i=0;i<x.size();i++){
    if(ans<x[i] && n<=m/x[i]){
      ans=x[i];
    }
  }
  cout << ans << endl;
  return 0;
}