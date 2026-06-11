#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int h,w;
  cin>>h>>w;
  vector<string>s(h+2);
  Rep(i,1,h+1){cin>>s[i];s[i]="."+s[i]+".";}
  string tmp="";
  rep(i,w+2)tmp=tmp+".";
  s[0]=tmp;
  s[h+1]=tmp;
  vector<vector<int>>mine(h,vector<int>(w));
  Rep(i,1,h+1){
    Rep(j,1,w+1){
      int tmpmi=0;
      if(s[i][j]=='#'){mine[i-1][j-1]=-1;continue;}
      if(s[i-1][j-1]=='#')tmpmi++;      
      if(s[i][j-1]=='#')tmpmi++;
      if(s[i+1][j-1]=='#')tmpmi++;
      if(s[i-1][j]=='#')tmpmi++;
      if(s[i+1][j]=='#')tmpmi++;
      if(s[i-1][j+1]=='#')tmpmi++;
      if(s[i][j+1]=='#')tmpmi++;
      if(s[i+1][j+1]=='#')tmpmi++;
      mine[i-1][j-1]=tmpmi;
      
    }}

  rep(i,h){rep(j,w){
      if(mine[i][j]==-1)cout<<"#";
      else cout<<mine[i][j];

    }cout<<endl;}
    
  return 0;
}
