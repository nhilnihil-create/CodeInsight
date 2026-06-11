#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main(){
  int h,w;cin>>h>>w;
  vector<vector<char>> v(h,vector<char>(w));
  rep(i,h){
    rep(j,w){cin>>v.at(i).at(j);}
  }
  string ans="Yes";
  bool a1,a2,a3,a4;
  rep(i,h){
    rep(j,w){
      a1=false;a2=false;a3=false;a4=false;
      if(v.at(i).at(j)=='#'){
        if(i>0){
          if(v.at(i-1).at(j)=='#'){
            a1=true;}
        }
        if(i<h-1){
          if(v.at(i+1).at(j)=='#'){
            a2=true;}
        }
        if(j>0){
          if(v.at(i).at(j-1)=='#'){
            a3=true;}
        }
        if(j<w-1){
          if(v.at(i).at(j+1)=='#'){
            a4=true;}
        }
        if(a1||a2||a3||a4){continue;}
        else{ans="No";break;}
      }    
    }
  }
  
  cout<<ans;
}