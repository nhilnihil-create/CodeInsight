#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> h(n);
  for(int i=0;i<n;i++)
    cin>>h.at(i);
  sort(h.begin(),h.end());
  int m=h.at(n-1)-h.at(0);
  for(int i=k-1;i<n;i++)
    m=min(m,h.at(i)-h.at(i-(k-1)));
  cout<<m<<endl;
}