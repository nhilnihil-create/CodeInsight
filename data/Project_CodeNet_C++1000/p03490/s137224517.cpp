#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin >> s;
  int n = s.size(),i,j,x,y,c = 0;cin >> x >> y;bool RL = true,RF = s[0]=='F';
  vector<int> L,U;
  for(i=0;i<n;i++){
    if(s[i] == 'T'){
      if(RL && c) L.push_back(c);
      else if(!RL && c) U.push_back(c);
      c = 0;RL ^= 1;
    }
    else c++;
  }
  if(RL && c) L.push_back(c);
  else if(!RL && c) U.push_back(c);
  bool dpl[L.size()+1][16001] = {},dpu[U.size()+1][16001] = {};//-8000 is 0,8000 is 16000
  dpl[0][8000] = dpu[0][8000] = 1;
  for(i=0;i<L.size();i++){
    for(j=0;j<=16000;j++){
      if(j-L[i]>=0) dpl[i+1][j] |= dpl[i][j-L[i]];
      if(i==0 && RF) continue;
      if(j+L[i]<=16000) dpl[i+1][j] |= dpl[i][j+L[i]];
    }
  }
  for(i=0;i<U.size();i++){
    for(j=0;j<=16000;j++){
      if(j-U[i]>=0) dpu[i+1][j] |= dpu[i][j-U[i]];
      if(j+U[i]<=16000) dpu[i+1][j] |= dpu[i][j+U[i]];
    }
  }
  cout << ((dpl[L.size()][x+8000] && dpu[U.size()][y+8000]) ? "Yes\n":"No\n");
}