#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,i,j,k,c,ph,pw;
  cin>>h>>w;
  vector<string> s(h);
  vector<int> dh={-1,-1,-1,0,0,1,1,1},dw={-1,0,1,-1,1,-1,0,1};
  for(i=0;i<h;i++) cin>>s.at(i);
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      if(s.at(i).at(j)=='#') continue;
      c=0;
      for(k=0;k<8;k++){
        ph=i+dh.at(k);
        pw=j+dw.at(k);
        if(ph<0||h<=ph||pw<0||w<=pw) continue;
        if(s.at(ph).at(pw)=='#') c++;
      }
      s.at(i).at(j)=(char)('0'+c);
    }
  }
  for(i=0;i<h;i++) cout<<s.at(i)<<endl;
}