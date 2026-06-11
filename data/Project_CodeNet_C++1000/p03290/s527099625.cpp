#include <bits/stdc++.h>
using namespace std;

int main(){
  int d, g;
  cin >> d >> g;
  vector<int> pd(d), cd(d);
  for(int i=0; i<d; ++i) cin >> pd[i] >> cd[i];
  int ans = 1001;
  for(int i=0; i<(1<<d); ++i){
    int nans = 0, point = 0;
    for(int j=0; j<d; ++j){
      if(i>>j &1){
        point += cd[j];
        point += pd[j] *(j+1) *100;
        nans += pd[j];
      }
    }
    int num = d-1;
    while(point < g){
      while(num >= 0 && (i>>num &1) == 1) --num;
      if(num <0) break;
      if(point + pd[num] *(num+1) *100 <g){
        point += pd[num] *(num+1) *100;
        nans += pd[num];
        --num;
      }else{
        nans += ((g-point) /100 -1)/(num+1) +1;
        break;
      }
    }
    ans = min(ans, nans);
  }
  cout << ans << endl;
}