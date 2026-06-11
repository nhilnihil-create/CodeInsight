#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  vector<char> S(3);
  vector<char> T(3);
  cin>>S[0]>>S[1]>>S[2]>>T[0]>>T[1]>>T[2];
  reverse(T.begin(),T.end());
  
  if(S==T){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}