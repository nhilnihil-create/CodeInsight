#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<int>>data(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      char a;
      cin >> a;
      if(a=='.') data.at(i).at(j)=0;
      else data.at(i).at(j)=-1;
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(data.at(i).at(j)==-1){
        bool count=false;
        if(i!=0){
          if(data.at(i-1).at(j)==-1) count=true;
        }
        if(j!=0){
          if(data.at(i).at(j-1)==-1) count=true;
        }
        if(j!=W-1){
          if(data.at(i).at(j+1)==-1) count=true;
        }
        if(i!=H-1){
          if(data.at(i+1).at(j)==-1) count=true;
        }
        if(!count){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
}