#include<iostream>
#include<vector>

using namespace std;

signed main(){

  const int MAX = 100;
  
  int A, B;
  int w, h;
  vector<vector<char> > ans(MAX+1, vector<char>(MAX+1));

  cin>>B>>A;

  A--, B--;
  
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < MAX; j++){
      if(j*2 < MAX) ans[i][j] = '#';
      else ans[i][j] = '.';
    }
  }
  
  for(int i = 0; i < MAX; i++){
    ans[0][i] = '#';
    ans[MAX-1][i] = '.';
  }

  cout<<MAX<<" "<<MAX<<endl;

  for(int i = 0; i < MAX; i+=2){
    
    for(int j = MAX-2; j >= 0; j-=2){
      
      if(A <= 0) break;
      if(j-1>=0)ans[j-1][i] = '.';
      if(j-1>=0)ans[j-1][i+1] = '.';
      ans[j][i+1] = '.';
      A--;
    }
    if(A <= 0) break;
  }

  for(int i = MAX-1; i >= 0; i-=2){
    for(int j = 1; j < MAX; j+=2){
      
      if(B <= 0) break;
      ans[j+1][i] = '#';
      ans[j+1][i-1] = '#';
      ans[j][i-1] = '#';
      B--;
    }
    if(B <= 0) break;
  }
  
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < MAX; j++){
      cout<<ans[i][j];
    }
    cout<<endl;
  }

  return 0;
}
