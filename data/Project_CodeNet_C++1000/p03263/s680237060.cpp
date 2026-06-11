#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
#include <stack>
#include <iomanip>
#include <limits>
using namespace std;
typedef long long ll;

int main(){
  int H,W;cin>>H>>W;
  vector<vector<int>> data(H,vector<int>(W,1));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>data[i][j];
    }
  }
  int count=0;
  vector<pair < pair<int,int>,pair<int,int> > > ans;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(data[i][j]%2==0){
        continue;
      }else{
        data[i][j]--;
        if(j!=W-1){
          ans.push_back({{i,j},{i,j+1}});
          data[i][j+1]++;
          count++;
        }else{
          if(i!=H-1){
            ans.push_back({{i,j},{i+1,j}});
            data[i+1][j]++;
            count++;
          }else{

          }
        }
      }
    }
  }
  cout<<count<<endl;
  for(int i=0;i<count;i++){
    cout<<ans[i].first.first+1<<" "<<ans[i].first.second+1<<" "<<ans[i].second.first+1<<" "<<ans[i].second.second+1<<endl;
  }
}
