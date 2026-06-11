#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  string S; cin>>S;
  int N=S.size();
  bool ikeru=0;
  if(S.substr(0, 7)=="keyence") ikeru=1;
  if(S.substr(0, 6)=="keyenc" && S.substr(N-1, 1)=="e") ikeru=1;
  if(S.substr(0, 5)=="keyen" && S.substr(N-2, 2)=="ce") ikeru=1;
  if(S.substr(0, 4)=="keye" && S.substr(N-3, 3)=="nce") ikeru=1;
  if(S.substr(0, 3)=="key" && S.substr(N-4, 4)=="ence") ikeru=1;
  if(S.substr(0, 2)=="ke" && S.substr(N-5, 5)=="yence") ikeru=1;
  if(S.substr(0, 1)=="k" && S.substr(N-6, 6)=="eyence") ikeru=1;
  if(S.substr(N-7, 7)=="keyence") ikeru=1;
  
  if(ikeru) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
