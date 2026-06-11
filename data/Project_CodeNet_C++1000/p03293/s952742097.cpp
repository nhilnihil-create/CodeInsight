#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  string S,T;
  cin>>S>>T;
  bool ans=false;
  rep(i,S.size()){
      bool h=true;
      rep(j,S.size()){
          if(S[(i+j)%S.size()]!=T[j]){
              h=false;
          }
      }

      if(h==true){
          ans=true;
          break;
      }
  }
  if(ans==false){
      cout<<"No"<<endl;
  }
  else{
      cout<<"Yes"<<endl;
  }
}
