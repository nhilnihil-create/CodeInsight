#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int N=S.size();

  int left=0,right=N-1;
  int cnt=0;
  bool fl=true;
  while(left<right){
    char s=S[left],t=S[right];
    if(s==t){
      ++left;
      --right;
    }
    else if(s=='x'){
      ++left;
      ++cnt;
    }
    else if(t=='x'){
      --right;
      ++cnt;
    }
    else{
      fl=false;
      break;
    }
  }

  if(fl) cout<<cnt<<endl;
  else cout<<-1<<endl;
}