#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;

int main(){
  string S;
  cin >> S;
  string Sb, Se;
  rep(i,7){
    Sb=S.substr(0,i);
    Se=S.substr(S.size()-7+i,S.size());
    if(Sb+Se=="keyence"){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;

  return 0;
}
