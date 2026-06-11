#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  sort(a.begin(),a.end(),greater<int>());
  int p=0;
  for(int i=0;i<n;i++)
    p+=a.at(i)*(i%2==0?1:-1);
  cout<<p<<endl;
}