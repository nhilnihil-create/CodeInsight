#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll K;
  cin>>K;
  if(K%2==0) {
cout<<(K/2)*(K/2)<<endl;
  }
  else {
cout<<(K/2+1)*(K/2)<<endl;
  }
}
