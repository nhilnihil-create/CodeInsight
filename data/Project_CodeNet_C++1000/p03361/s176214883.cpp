#include<bits/stdc++.h>
using namespace std;

bool solve(vector<vector<char>>hyo){
  bool ans=true;
  for(int i=0;i<hyo.size();i++){
    for(int j=0;j<hyo.at(0).size();j++){
      if(hyo.at(i).at(j)=='#'){
      bool ok=false;
      if(j!=0&&hyo.at(i).at(j-1)=='#')
        ok=true;
      if(j!=hyo.at(0).size()-1&&hyo.at(i).at(j+1)=='#')
        ok=true;
      if(i!=0&&hyo.at(i-1).at(j)=='#')
        ok=true;
      if(i!=hyo.size()-1&&hyo.at(i+1).at(j)=='#')
        ok=true;
      if(!ok)
        ans=false;
      }
    }
  }
  return ans;
}
int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>>hyo(h,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)
      cin >> hyo.at(i).at(j);
  }
  cout << (solve(hyo)?"Yes":"No") << endl;
  return 0;
}