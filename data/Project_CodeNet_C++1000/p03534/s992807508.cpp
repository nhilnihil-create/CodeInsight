#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int s=S.size();
  int a=0,b=0,c=0;
  for(int i=0;i<s;i++){
    if(S[i]=='a')a++;
    if(S[i]=='b')b++;
    if(S[i]=='c')c++;
  }
  string ans="NO";
  if(s%3==0){
    if(a==b && b==c){ans="YES";}
  }
  else if(s%3==1){
    int m=min({a,b,c});
    if(a+b+c-3*m==1){ans="YES";}
  }
  else{
    int M=max({a,b,c});
    if(3*M-a-b-c==1){ans="YES";}
  }
  cout << ans << endl;
}