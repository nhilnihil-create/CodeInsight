#include <bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  vector<long> x, y;
  long co = 0, flag = 0, sumx = 0, sumy = 0;
  for(int i = 0; i < S.size(); i++){
    if(S.at(i) == 'F')co++;
    else{
      if(flag == 0){
        flag = 1;
        if(co == 0)continue;
        x.push_back(co);
        sumx += co;
      } else {
        flag = 0;
        if(co == 0)continue;
        y.push_back(co);
        sumy += co;
      }
      co = 0;
    }
  }
  if(flag == 0){
     x.push_back(co);
     sumx += co;
  } else {
    y.push_back(co);
     sumy += co;
  }
  long a, b;
  cin >> a >> b;
  if(S.at(0) == 'F'){
    a -= x.at(0);
    sumx -= x.at(0);
    x.at(0) = 0;
  }
  if(abs(a) > sumx || abs(b) > sumy){
    cout << "No" << endl;
    return 0;
  }
  vector<long> dpx(sumx * 2 + 1), dpy(sumy * 2 + 1);
  dpx.at(sumx * 2) = 1;
  dpy.at(sumy * 2) = 1;
  for(int i = 0; i < x.size(); i++){
    for(int j = 0; j < dpx.size(); j++){
      if(dpx.at(j) == 1){
        if(j - x.at(i) * 2 >= 0){
          dpx.at(j - x.at(i) * 2) = 1;
        }
      }
    }
  }
  for(int i = 0; i < y.size(); i++){
    for(int j = 0; j < dpy.size(); j++){
      if(dpy.at(j) == 1){
        if(j - y.at(i) * 2 >= 0){
          dpy.at(j - y.at(i) * 2) = 1;
        }
      }
    }
  }
  if(dpx.at(a + sumx) == 1 && dpy.at(b + sumy) == 1)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}