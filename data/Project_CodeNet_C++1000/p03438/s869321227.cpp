#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long bdai,aguudai,n,akidai,cou;
  string str;
  str="Yes";
  cou=0;
  bdai=0;
  aguudai=0;
  akidai=0;
  cin>>n;
  vector<long> aa(n);
  vector<long> bb(n);
  for(int i=0; i<n; i++){
    cin>>aa.at(i);
  }
  for(int i=0; i<n; i++){
    cin>>bb.at(i);
  }
  for(int i=0; i<n; i++){
    if(bb.at(i)<aa.at(i)){
      bdai=bdai-bb.at(i)+aa.at(i);
    }
    else if((bb.at(i)-aa.at(i))%2==0){
      aguudai=aguudai+bb.at(i)-aa.at(i);
    }
    else{
      akidai=akidai+bb.at(i)-aa.at(i);
      cou++;
    }
  }
  if(bdai>0){
    if(aguudai-2*bdai<0){
      bdai=bdai*2-aguudai;
      if(bdai>akidai-cou){
        str="No";
      }
    }
  }
  cout<<str;
}