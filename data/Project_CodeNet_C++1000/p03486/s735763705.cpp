#include<bits/stdc++.h>
using namespace std;
int main(){
  string x,y;
  cin>>x>>y;
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  reverse(y.begin(),y.end());
  if(x<y) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}