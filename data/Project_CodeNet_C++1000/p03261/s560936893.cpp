#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  set<string> S;
 vector<string> vec(N);
  for(ll i=0;i<N;i++) {
cin>>vec[i];
  }
  
for(ll i=0;i<N;i++) {
if(S.count(vec[i])) {
cout<<"No"<<endl;
  return 0;
}
  S.insert(vec[i]);
}
  
  
  for(ll i=0;i<N-1;i++) {
if(vec[i].back()!=vec[i+1][0]) {
cout<<"No"<<endl;
  return 0;
}
  }
  
  
  cout<<"Yes"<<endl;
}
