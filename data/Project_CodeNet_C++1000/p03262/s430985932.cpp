#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> x(N+1);
  for(int &i:x)
    cin>>i;
  sort(x.begin(),x.end());
  int j=0;
  for(int i=0;i<N;i++)
    j=__gcd(j,x[i+1]-x[i]);
  cout<<j<<endl;
}