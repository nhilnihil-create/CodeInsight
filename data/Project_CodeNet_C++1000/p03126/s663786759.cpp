#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<bool> l(m,1);
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    vector<bool> li(m,0);
    for(int j=0;j<k;j++){
      int a;
      cin>>a;
      li.at(a-1)=1;
    }
    for(int j=0;j<m;j++)
      l.at(j)=l.at(j)&&li.at(j);
  }
  int c=0;
  for(int i=0;i<m;i++)
    if(l.at(i))
      c++;
  cout<<c<<endl;
}