#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int a,b,c;cin>>a>>b>>c;
  if(a<c&&b<c){cout<<a*b/2;}
  else if(a<b&&c<b){cout<<a*c/2;}
  else{cout<<b*c/2;}
              
}
      

