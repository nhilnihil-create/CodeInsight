#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  set<char> S;
  for(ll i=0;i<N;i++) {
    char d;
    cin>>d;
    S.insert(d);
  }
  if(S.size()==3) {
cout<<"Three"<<endl;
  }
  else {
cout<<"Four"<<endl;
  }
}
