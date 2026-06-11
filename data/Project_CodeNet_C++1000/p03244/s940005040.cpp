#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> ve(1000000), vo(1000000);
  for(int i = 0; i < n; ++i){
    int k;
    cin >> k;
    if(i % 2){
      vo.at(k).first++;
      vo.at(k).second = k;
    }
    else{
      ve.at(k).first++;
      ve.at(k).second = k;
    }
  }
  
  sort(vo.begin(), vo.end());
  reverse(vo.begin(), vo.end());
  sort(ve.begin(), ve.end());
  reverse(ve.begin(), ve.end());
  
  int sum = vo.at(0).first + ve.at(0).first;
  if(vo.at(0).second == ve.at(0).second){
    int s = vo.at(0).first + ve.at(1).first;
    int t = vo.at(1).first + ve.at(0).first;
    if(s > t) sum = s;
    else sum = t;
  }
  
  cout << n - sum << endl;
}