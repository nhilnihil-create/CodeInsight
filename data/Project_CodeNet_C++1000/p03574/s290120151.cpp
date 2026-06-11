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
      if(data.at(i).at(j)==0){
        int count=0;
        if(i!=0){
          if(data.at(i-1).at(j)==-1) count++;
        }
        if(i!=0&&j!=0){
          if(data.at(i-1).at(j-1)==-1) count++;
        }
        if(i!=0&&j!=W-1){
          if(data.at(i-1).at(j+1)==-1) count++;
        }
        if(j!=0){
          if(data.at(i).at(j-1)==-1) count++;
        }
        if(j!=W-1){
          if(data.at(i).at(j+1)==-1) count++;
        }
        if(i!=H-1){
          if(data.at(i+1).at(j)==-1) count++;
        }
        if(i!=H-1&&j!=0){
          if(data.at(i+1).at(j-1)==-1) count++;
        }
        if(i!=H-1&&j!=W-1){
          if(data.at(i+1).at(j+1)==-1) count++;
        }
        data.at(i).at(j)=count;
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(data.at(i).at(j)==-1) cout << "#";
      else cout << data.at(i).at(j);
    }
    cout << endl;
  }
}
