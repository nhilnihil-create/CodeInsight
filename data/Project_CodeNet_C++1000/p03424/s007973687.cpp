#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<char> S(N);
  for(int i=0;i<N;i++){
    cin>>S[i];
  }
  sort(S.begin(),S.end());
  
  if(S[N-1]=='Y'){
    cout<<"Four"<<endl;
  }
  else{
    cout<<"Three"<<endl;
  }
}