#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,i,cx,cy,H;
  cin>>n;
  vector<vector<int>> hxy(n,vector<int>(3));
  for(i=0;i<n;i++) cin>>hxy.at(i).at(1)>>hxy.at(i).at(2)>>hxy.at(i).at(0);
  sort(hxy.begin(),hxy.end());
  reverse(hxy.begin(),hxy.end());
  for(cx=0;cx<=100;cx++){
    for(cy=0;cy<=100;cy++){
      H=-1;
      for(i=0;i<n;i++){
        if(hxy.at(i).at(0)>0){
          if(H==-1) H=hxy.at(i).at(0)+abs(hxy.at(i).at(1)-cx)+abs(hxy.at(i).at(2)-cy);
          else if(H!=hxy.at(i).at(0)+abs(hxy.at(i).at(1)-cx)+abs(hxy.at(i).at(2)-cy)) break;
        }
        else if(hxy.at(i).at(0)==0){
          if(H-abs(hxy.at(i).at(1)-cx)-abs(hxy.at(i).at(2)-cy)>0) break;
        }
      }
      if(i==n){
        cout<<cx<<' '<<cy<<' '<<H<<endl;
        cx=100; cy=100;
      }
    }
  }
}