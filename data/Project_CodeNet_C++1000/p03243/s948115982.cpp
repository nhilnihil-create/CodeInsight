#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  for(ll i=1;i<10;i++) {
if((i-1)*111<N&&i*111>=N) {
cout<<i*111<<endl;
}
  }
  
}
