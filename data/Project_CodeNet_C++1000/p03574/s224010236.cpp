#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  vector <string> s(h);
  for(int i=0;i<h;i++){
    cin >> s.at(i);
  }
  
  vector <int> aroundX = {-1, 0, 1, 1, 1, 0,-1,-1};
  vector <int> aroundY = {-1,-1,-1, 0, 1, 1, 1, 0};
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s.at(i).at(j)=='#')continue;
      int cnt=0;
      for(int k=0;k<8;k++){
        int x,y;
        x=i+aroundX.at(k);
        y=j+aroundY.at(k);
        if(x<0||x>=h||y<0||y>=w)continue;
        if(s.at(x).at(y)=='#'){
          cnt++;
        }
      }
      s.at(i).at(j)='0'+cnt;
    }
  }
  
  for(int i=0;i<h;i++){
    cout << s.at(i) << endl;
  }
  return 0;
}