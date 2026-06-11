#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int64_t> v(87);
  v[0]=2;
  v[1]=1;
  for(int i=2;i<87;i++)v[i]=v[i-1]+v[i-2];
  cout<<v[N]<<endl;
}