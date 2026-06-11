#include<bits/stdc++.h>
using namespace std ;


bool dfs(int i , int j , vector<vector<char>> s, int H , int W){
  if(i <= H-2 && s.at(i+1).at(j) == '#') return true ; 
  else if(i >= 1 && s.at(i-1).at(j) == '#') return true ; 
  else if(j <= W-2 && s.at(i).at(j+1) == '#' ) return true; 
  else if(j >= 1 && s.at(i).at(j-1) == '#' ) return true ; 
  else return false ; 
}

int main(){
  int H , W ; 
  cin >> H >> W ; 
  vector<vector<char>> s(H , vector<char>(W)) ;
  
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      cin >> s.at(i).at(j) ; 
    }
  }
  
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < W ; j++){
      if(s.at(i).at(j) == '#'){
        if(dfs(i , j ,s , H , W)) continue ; 
        else{
          cout << "No" << endl;
          return 0 ; 
        }
      }      
    }
  }
    
  cout << "Yes" << endl; 
  
  
}