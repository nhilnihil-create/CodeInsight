#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 set<char> S;
  for(ll i=0;i<3;i++) {
char x;
    cin>>x;
    S.insert(x);
  }
  
  if(S.size()==3) {
cout<<"Yes"<<endl;
  }
  else {
cout<<"No"<<endl;
  }
}