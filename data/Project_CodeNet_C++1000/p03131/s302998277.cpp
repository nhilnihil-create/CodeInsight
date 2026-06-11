#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

int main(){
  ll K,A,B;
  cin>>K>>A>>B;
  if(B - A > 2){
    cout << A + ((K-A+1)/2)*(B-A) + (K-A+1)%2 << endl;
  }else{
    cout << K+1 << endl;
  }
  return 0;
}
