#include <bits/stdc++.h>
#include <cmath>
#include <stdio.h>

using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> L(N);
  for(int i=0;i<N;i++){
    cin>>L.at(i);
  }
  sort(L.begin(),L.end());
  long ans=0;
  for(int i=0;i<N-1;i++){
    ans+=L.at(i);
  }
  if(L.at(N-1)<ans) cout<<"Yes";
  else cout<<"No";
}
