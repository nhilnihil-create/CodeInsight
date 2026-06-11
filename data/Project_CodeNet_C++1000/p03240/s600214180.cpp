#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n; cin>>n;
  int ansx{}, ansy{}, ansh{};
  vector<int> x(n),y(n),h(n);
  for(int i=0; i<n; i++){
    cin>>x.at(i)>>y.at(i)>>h.at(i);
  }
  for(int cx=0; cx<=100; cx++){
    for(int cy=0; cy<=100; cy++){
      bool flg{};
      int hight{-1};
      int hmax = 1e9;
      hmax *= 2;
      for(int i=0; i<n; i++){
        if(h.at(i)==0){
          hmax = min(hmax,abs(x.at(i)-cx)+abs(y.at(i)-cy));
        }
        else{
          int hi = h.at(i)+abs(x.at(i)-cx)+abs(y.at(i)-cy);
          if(hight<0){
            hight = hi;
          }
          else{
            if(hight!=hi){
              flg = 1;
              break;
            }
          }
        }
      }
      if(flg) continue;
      else {
        if(hight>hmax) continue;
        ansx = cx;
        ansy = cy;
        ansh = hight;
        
      }
    }
  }
  cout <<ansx<<' '<<ansy<<' '<<ansh<<endl;
}