#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define ALL(x) begin(x),end(x)
#define ll long long
#define ld long double

int main(){
  ll h,w; cin >> h >> w;
  vector<vector<string>> map(h+2,vector<string>(w+2));
  rep(i,h+2) rep(j,w+2) map.at(i).at(j) = ".";
  rep(i,h+2){
    if(i==0||i==h+1) continue;
    rep(j,w+2){
      if(j==0||j==w+1) continue;
      char tmp; cin >> tmp;
      map.at(i).at(j) = tmp;
    }
  }
  
 for(int i=1; i<h+1; i++){
   for(int j=1; j<w+1; j++){
     if(map.at(i).at(j)=="#"){
       cout << map.at(i).at(j);
     }else{
       //周辺マス地雷探査
       int jirai = 0;
       for(int m=i-1;m<=i+1;m++) for(int n=j-1;n<=j+1;n++) if(map.at(m).at(n)=="#") jirai++;
       cout << jirai;
     }
   }
   cout << endl;
 }
}