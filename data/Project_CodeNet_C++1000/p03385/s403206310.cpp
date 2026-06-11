#include<bits/stdc++.h>
using namespace std;
int main(){
  string q;
  int l;
  vector<int> b(3);
  cin>>q;
  for(l=0;l<3;l++) b.at(q.at(l)-'a')=1;
  if(b.at(0)==1&&b.at(1)==1&&b.at(2)==1) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}