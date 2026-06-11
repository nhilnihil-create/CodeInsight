#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
 if(abs(c-a)<=d) {
cout<<"Yes"<<endl;
 }
  else if(abs(b-a)<=d&&abs(c-b)<=d) {
cout<<"Yes"<<endl;
  }
  else {
cout<<"No"<<endl;
  }
}