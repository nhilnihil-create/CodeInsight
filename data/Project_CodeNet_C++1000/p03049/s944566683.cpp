#include <iostream>
#include <algorithm>
#include <queue>
#include <cassert>
#include <set>
using namespace std; typedef long long ll; const int MINF=-1e9; typedef pair<int,int> P;

int main() {
  int n; cin>>n;
  string s[n]; for(int i=0;i<n;i++) cin>>s[i];
  int an=0; int u[3]={0,0,0}; // xA, BA, Bx
  for(int i=0;i<n;i++) {
    for(int j=0;j<s[i].size()-1;j++) {
      if (s[i][j]=='A'&&s[i][j+1]=='B') an++;
    }
    if (s[i].back()=='A') {
      if (s[i].front()=='B') u[1]++;
      else u[0]++;
    } else if (s[i].front()=='B') u[2]++;
  }
  if (u[1]>0){
    an+=u[1]-1; u[1]=0;
    if (u[0]>0) an++, u[0]--;
    if (u[2]>0) an++, u[2]--;
  }
  an+=min(u[0],u[2]);
  cout<<an<<endl;
}