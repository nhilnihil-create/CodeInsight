#include<bits/stdc++.h>
using namespace std;

int main(){
  int w,h;
  cin >> h >> w;
  vector<vector<char>>hyo(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> hyo.at(i).at(j);
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(hyo.at(i).at(j)=='.'){
        int su=0;
        for(int k=i-1;k<i+2;k++){
          for(int l=j-1;l<j+2;l++){
            if(k>=0&&k<h&&l>=0&&l<w)
            if(hyo.at(k).at(l)=='#')
              su++;
          }
        }
        hyo.at(i).at(j)=su+48;
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout << hyo.at(i).at(j);
    }
    cout << endl;
  }
}