#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

signed main(void){ 

  string s; cin >> s;
  int n = (int)s.size();
  
  if( s.back() == '1'|| s.front() == '0'){ cout <<"-1" << endl; return 0;}
  for(int i = 0; i <= n-2; i++){
    if( s[i] != s[n-i-2] ){ cout << "-1" << endl; return 0;}
  }
  
  //以下、対称性がある
  int last = 0;
  vector<int> vec;
  vector<pair<int,int>> edge;
  for(int i = 1; i < n; i++){ 
    if( s[i] == '0'){ vec.push_back(i);}
    else{ 
      //iとvecに入っていたものを全て繋げる
      edge.push_back({i,last});
      
      for(int j = 0; j < (int)vec.size(); j++){ 
        edge.push_back({i,vec[j]});
      }
      
      last = i;
      vec.clear();
    }
  }
  
  edge.push_back({last,n-1});
  
  for(auto ans : edge ){ cout << ans.first+1 << " " << ans.second+1 << endl;}
  
  return 0;
}