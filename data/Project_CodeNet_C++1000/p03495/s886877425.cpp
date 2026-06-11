#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  map<int,int> a;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a[x]++;
  }
  vector<int> b;
  for(auto x:a)
    b.push_back(x.second);
  sort(b.begin(),b.end());
  int c=0;
  for(int i=0;i<(int)b.size()-k;i++)
    c+=b.at(i);
  cout<<c<<endl;
}