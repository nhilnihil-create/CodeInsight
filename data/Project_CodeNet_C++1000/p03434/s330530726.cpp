#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> a(N);
  for (int i=0;i<N;i++)
    cin>>a.at(i);
  sort(a.begin(),a.end());
  
  int p=0;
  int q=0;
  for (int i=0;i<(N+1)/2;i++)
    p+=a.at(2*i);
  for (int i=0;i<N/2;i++)
    q+=a.at(2*i+1);
  cout<<max(p,q)-min(p,q)<<endl;
}