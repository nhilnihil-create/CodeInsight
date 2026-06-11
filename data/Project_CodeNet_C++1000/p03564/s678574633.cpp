#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
 LL N,K; cin>>N>>K;
 LL X=1;

 while(N--){
  if(X<K) X*=2;
  else X+=K;
 }
 cout<<X<<endl;

 return 0;
}


