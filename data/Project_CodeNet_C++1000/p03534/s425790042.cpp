#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int a=0,b=0,c=0;
  for(int i=0;i<S.length();i++){
    if(S[i]=='a')a+=1;
    else if(S[i]=='b')b+=1;
    else if(S[i]=='c')c+=1;
  }
  if(abs(a-b)<=1 && abs(a-c)<=1 && abs(b-c)<=1)cout <<"YES";
  else cout <<"NO";
}

