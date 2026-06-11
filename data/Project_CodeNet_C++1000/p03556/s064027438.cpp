#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ll N;
  cin >> N;
  ll rt = sqrt(N);
  ll ans = rt;
  for(ll i = rt; i <= N && i*i <= N; i++){
    if(i > ans){
      ans = i;
    }
  }
  cout << ans*ans << endl;
  
}