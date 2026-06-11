#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  int A,B,K;
  cin>>A>>B>>K;
  if(K<=(B-A)/2){
    for(int i=A;i<A+K;i++){
      cout<<i<<endl;
    }
    for(int i=B-K+1;i<=B;i++){
      cout<<i<<endl;
    }
  }
  if(K>(B-A)/2){
    for(int i=A;i<=B;i++){
      cout<<i<<endl;
    }
  }
}