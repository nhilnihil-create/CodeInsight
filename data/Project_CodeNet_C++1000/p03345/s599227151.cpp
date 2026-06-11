#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=1000000007;
const long double PI=3.1415926535;

int main() {
  ll K,A,B,C;
  cin>>A>>B>>C>>K;
  
  if(K%2==0){
    cout<<A-B;
  }
  else{
    cout<<B-A;
  }
  
}