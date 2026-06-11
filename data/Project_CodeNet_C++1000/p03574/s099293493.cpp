#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>>a(h,vector<char>(w));
  for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin >> a.at(i).at(j);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(a.at(i).at(j)=='.'){
        int n=0;
        for(int k=-1;k<2;k++){
          for(int l=-1;l<2;l++){
            if(i+k>=0&&i+k<h&&j+l>=0&&j+l<w){
              n+=(a.at(i+k).at(j+l)=='#');
            }
          }
        }
        a.at(i).at(j)=n+'0';
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout << a.at(i).at(j);
    }
    cout << '\n';
  }
  return 0;
}