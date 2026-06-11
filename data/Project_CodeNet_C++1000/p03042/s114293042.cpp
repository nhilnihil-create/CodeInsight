#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll S;
  cin>>S;
  ll A=S/100;
  ll B=S%100;
  bool a,b;
  a=false;
  b=false;
  if(0<A&&A<13) {
a=true;
  }
  if(0<B&&B<13) {
b=true;
  }
  
  if(a&&b) {
cout<<"AMBIGUOUS"<<endl;
  }
  else if(a) {
cout<<"MMYY"<<endl;
  }
  else if(b) {
cout<<"YYMM"<<endl;
  }
  else {
cout<<"NA"<<endl;
  }
}
  
