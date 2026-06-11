#include <bits/stdc++.h>
using namespace std;
int ans=0;
void kaage(int N,string S){
  bool A=false,B=false,C=false;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='3')A=true;
    if(S.at(i)=='5')B=true;
    if(S.at(i)=='7')C=true;
  }
  long long a=atoll(S.c_str());
  if(A&&B&&C&&N>=a)ans++;
  if(S.size()==10)return;
  kaage(N,S+"3");
  kaage(N,S+"5");
  kaage(N,S+"7");
}
int main(){
  int N;cin>>N;string S="";
  kaage(N,S);
  cout<<ans<<endl;
}