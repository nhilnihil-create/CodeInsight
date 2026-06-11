#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

int main() {
  ll A,B,K;
  cin>>A>>B>>K;
  ll C=min(A,B);
  
  while(K>0) {
    if(A%C==0&&B%C==0) {
K--;
    }
    C--;
  }
  
  cout<<C+1<<endl;
}

 
      
