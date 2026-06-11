#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
 
int N, Q;
 
int falldir(int i, string &str, vector<pair<char,char>> &spells){
  for(auto s : spells){
    char t = s.first; char d = s.second;
    if(t==str[i]){
      // hit
      i += (d=='L'?-1:1);
      if(i<0){ return -1; }
      else if(i>=N){ return 1; }
    }
  }
  return 0;
}
 
int main(){
  cin>>N>>Q;
  string s;
  cin>>s;
  
  vector<pair<char,char>> spells;
  
  for(int h=1;h<=Q;h++){
    char t,d; cin>>t>>d;
    spells.push_back(make_pair(t,d));
  }
  
  int l=0, u=N;
  while(u-l>1){
    int m = (u+l)/2;
    if(falldir(m,s,spells)<0) l=m;
    else u=m;
  }
  int lower = l;
  
  l=0; u=N;
  while(u-l>1){
    int m = (u+l)/2;
    if(falldir(m,s,spells)>0) u = m;
    else l=m;
  }
  int upper = u;
  int ans = upper-lower-1;
  
  cout<<max(ans,0)<<endl;
}