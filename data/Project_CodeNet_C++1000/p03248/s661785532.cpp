#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){ 
  string s; cin >> s;
  int n = s.size();
  
  if( s.front() == '0' || s.back() == '1'){ 
    cout << -1 << endl; return 0;
  }

  for(int i = 0; i < n-1; i++){
    
    if( s[i] != s[n-2-i]){ cout << -1 << endl; return 0;
                         }
  }

  int top = 0;
  
  vector<pair<int,int>> ans;
  
  for(int i = 0; i < n-1 ;i++){ 
    ans.push_back({top,i+1});
    if( s[i] == '1'){ top = i+1;} //先頭移動
    
  }
  
  for(auto ne : ans ){ 
    
    cout << ne.first+1 << " " << ne.second+1 << endl;
    
  }

  return 0;
}