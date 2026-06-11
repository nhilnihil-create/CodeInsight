#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll a,b;
  cin>>a>>b;
  ll c=a+b;
  if(c%2==0) {
cout<<c/2<<endl;
  }
  else {
cout<<c/2+1<<endl;
  }
}