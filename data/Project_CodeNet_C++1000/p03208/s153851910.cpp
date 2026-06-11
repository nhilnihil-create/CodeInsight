#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  vector<int> h(N);
  for(int &i:h)
    cin>>i;
  sort(h.begin(),h.end());
  int j=1000000000;
  for(int i=0;i<=N-K;i++){
    j=min(j,h[i+K-1]-h[i]);
  }
  cout<<j<<endl;
}