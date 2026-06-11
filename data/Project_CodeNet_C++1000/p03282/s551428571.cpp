#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int K;
  cin>>S>>K;
  int N=S.size();
  int x=1;
  for(int i=0;i<K;i++){
    if(S[i]!='1'){
      cout<<S[i];
      x*=0;
      break;
    }
  }
    if(x==1) cout<<1;  
}
