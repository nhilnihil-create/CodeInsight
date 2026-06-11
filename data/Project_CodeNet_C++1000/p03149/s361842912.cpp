#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int>x(4);
  for(int i=0;i<4;i++)cin>>x.at(i);
  sort(x.begin(),x.end());
  if(x.at(0)==1&&x.at(1)==4&&x.at(2)==7&&x.at(3)==9)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}