#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  long long A,B,K;
  cin>>A>>B>>K;
  
  
  set<int> S;
  for(int i=0;i<K;i++){
    if(A<=B-i){
      S.insert(B-i);
    }
    if(A+i<=B){
      S.insert(A+i);
    }
  }
  
  while(!(S.empty())){
    cout<<*begin(S)<<endl;
    S.erase(*begin(S));
  }
}