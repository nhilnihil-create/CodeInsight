#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  



int main(){
  int n;  cin >> n;
  map<int, int> odd, even;
  for(int i=0; i<n; i++){
    int x;  cin >> x;
    if(i%2==1) even[x] += 1;
    else odd[x] += 1;
  }
  

  int okey1, oc1=0, oc2=0; 
  int ekey1, ec1=0, ec2=0; 
  for(auto x: odd){
    if(oc1<x.second){
      oc2 = oc1;  
      oc1 = x.second; okey1 = x.first;
    }else if(oc2<x.second){
      oc2 = x.second; 
    }
  }
  for(auto x: even){
    if(ec1<x.second){
      ec2 = ec1;  
      ec1 = x.second; ekey1 = x.first;
    }else if(ec2<x.second){
      ec2 = x.second;
    }
  }
  ll ans = 0;
  if(okey1==ekey1){
    ans = n - max(oc1+ec2, oc2+ec1);
  }else ans = n - (ec1+oc1);

  cout << ans << endl;
}