#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  string S;cin>>S;
  
  int c1=0;
  int c2=0;
  int c3=0;
  
  for(int i=0;i<3;i++){
    if(S[i]=='a'){
      c1++;
    }
    else if(S[i]=='b'){
      c2++;
    }
    else{
      c3++;
    }
  }
  
  if(c1==1&&c2==1&&c3==1){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
    