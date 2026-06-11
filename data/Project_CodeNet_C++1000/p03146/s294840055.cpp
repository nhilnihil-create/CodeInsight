#include<bits/stdc++.h>
using namespace std;
int main(){
int s;
cin>>s;
vector<int> v(1000000,0);
int count=1;
v.at(s-1)=1;
while(true){
  count++;
  if(s%2==0) s=s/2;
  else s=3*s+1;
  v.at(s-1)++;
  if(v.at(s-1)==2) break;
}
cout<<count<<endl;
}