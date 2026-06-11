#include<bits/stdc++.h>
using namespace std;
int main(){
 vector<vector<int>> to(4);
 vector<bool> visited(4,false);
 vector<int>vec(4); for(int i = 0; i < 4; i++){ vec[i] = i;}
 
  for(int i = 0; i < 3; i++){
    int a,b; cin >> a >> b; a--; b--; 
    to[a].push_back(b); to[b].push_back(a);}
    
  
  do{
    for(int i = 0; i < 4; i++){ visited[i] = false;}
    
    //vec[0]↪︎...↪︎vec[3]の順にたどり着けるかを調べる
    visited[vec[0]] = true;
    bool f = true;
    for(int j = 0; j <= 2; j++){
      bool flag = false;
    for(int i = 0; i < (int)to[vec[j]].size(); i++){
      if(to[vec[j]][i] == vec[j+1]){ visited[vec[j+1]] = true; flag = true;
          if( j == 2){ cout << "YES" << endl; return 0;}}}
      if(!flag){ f = false; break;} }
    
    if(!f){ continue;}
    
        
    
  }while(next_permutation(vec.begin(),vec.end()));
         
   cout << "NO" << endl; return 0;}
    