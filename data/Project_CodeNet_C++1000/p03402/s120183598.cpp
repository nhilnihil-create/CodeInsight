#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,h=100,w=50,i,j,k;
  vector<string> s(100);
  cin>>a>>b;
  cout<<h<<' '<<w<<endl;
  for(j=0;j<w;j++) s.at(0)+='.';
  for(i=1;i<h/2;i++) s.at(i)=s.at(0);
  for(j=0;j<w;j++) s.at(h/2)+='#';
  for(i=h/2+1;i<h;i++) s.at(i)=s.at(h/2);
  for(k=0;k<b-1;k++) s.at(1+k/(w/2)*2).at(k%(w/2)*2)='#';
  for(k=0;k<a-1;k++) s.at(h/2+1+k/(w/2)*2).at(k%(w/2)*2)='.';
  for(i=0;i<h;i++) cout<<s.at(i)<<endl;
}