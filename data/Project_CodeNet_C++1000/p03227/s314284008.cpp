#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S,A;cin>>S;
  A=S;
  if(S.size()==3){A=S[2];A+=S[1];A+=S[0];}
  cout<<A<<endl;
}