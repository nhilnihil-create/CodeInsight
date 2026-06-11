#include<bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<char>> data(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> data.at(i).at(j);
    }
  }
  vector<int> dx={-1,0,1,0};
  vector<int> dy={0,1,0,-1};
  bool jd = true;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(data.at(i).at(j)=='#'){
        bool found=false;
        for(int k=0;k<4;k++){
          int x=i+dx.at(k);
          int y=j+dy.at(k);
          if(x>=0&&x<h&&y>=0&&y<w&&data.at(x).at(y)=='#'){found=true;}
        }
        if(!found){jd=false;}
      }
    }
  }
  if(jd){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
