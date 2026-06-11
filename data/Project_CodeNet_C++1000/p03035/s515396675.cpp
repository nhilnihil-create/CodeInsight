#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
 ll N,B;
  cin>>N>>B;
  if(N>12) {
cout<<B<<endl;
  }
  else if(N>5) {
cout<<B/2<<endl;
  }
  else {
    cout<<0<<endl;
  }
}