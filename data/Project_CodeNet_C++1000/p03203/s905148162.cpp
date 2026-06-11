#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int>>xy;
  vector<int>dl(max(h, w), 10000000); //x-yがキー、禁止xの下限
  for(int i=0; i<n; i++){
    int x, y;
    cin >> x >> y;
    if(x>=y)xy.push_back(make_pair(x, y));
  }
  sort(xy.begin(), xy.end());
  int nowl=0; //今の所OKなx-yの下限
  for(int i=0; i<xy.size(); i++){
    if(xy[i].first-xy[i].second==nowl){
      dl[nowl]=xy[i].first;
      nowl++;
    }
  }
  int ret=0;
  for(pair<int, int>p: xy){
    int x=p.first, y=p.second;
    if(x-y>0 && dl[x-y-1]>=x){
      ret=x-1;
      break;
    }
  }
  if(ret==0)ret=h;
  cout << ret;
  return 0;
}
