#include<bits/stdc++.h>
using namespace std;
int main(){
  string S,T="keyence";
  cin>>S;
  for(int i=0;i<=T.size();i++){
    if(S.substr(0,i)==T.substr(0,i) && S.substr(S.size()-(7-i))==T.substr(i)){
      puts("YES");
      return 0;
    }
  }
  puts("NO");
}