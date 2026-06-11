#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,e,f,g;
  cin >>a >>b >>c >>d;
  e = std::abs(c-a);
  f = std::abs(b-a);
  g = std::abs(c-b);
  if(e<=d){
    cout <<"Yes" <<endl;
  }
  else if(f<=d&&g<=d){
    cout <<"Yes" <<endl;
  }
  else{
    cout <<"No" <<endl;
  }
}