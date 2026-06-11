#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  char X,Y;
  cin>>X>>Y;
  if(X-Y==0) {
cout<<'='<<endl;
  }
  else if(X>Y) {
cout<<'>'<<endl;
  }
  else {
cout<<'<'<<endl;
  }
}