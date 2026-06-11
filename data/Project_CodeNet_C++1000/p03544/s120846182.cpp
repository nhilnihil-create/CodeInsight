#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)

int N;
vector<long long> L(86);
long long ans;

long long luca(int n){
  if(n==0) return 2;
  if(n==1) return 1;
  if(L.at(n-1)==0){
    L.at(n-1)=luca(n-1);
  }
  if(L.at(n-2)==0){
    L.at(n-2)=luca(n-2);
  }
  return L.at(n-1)+L.at(n-2);
}

int main() {
  cin>>N;
  ans = luca(N);
  cout<<ans<<endl;
}