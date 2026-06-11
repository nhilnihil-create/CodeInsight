#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
  cin>>N;
  string S=to_string(N);
  ll A=0;
 for(auto x:S) {
A+=x-'0';
 }
  if(N%A==0) {
cout<<"Yes"<<endl;
  }
  else {
cout<<"No"<<endl;
  }
}
  
  