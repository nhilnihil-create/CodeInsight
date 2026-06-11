#include <bits/stdc++.h>
using namespace std;

int main(){
  int g,n,x;
  cin >> g >> n >> x;
  map<int,int>kane;
  int baf;
  for(int i=0;i<n;i++){
    cin >> baf;
    kane[baf]=1;
  }
  int monA=0,monB=0;
  for(int i=x;i<g;i++){
    if(kane[i]==1)
      monA++;
  }
  for(int i=x;i>0;i--){
    if(kane[i]==1)
      monB++;
  }
  cout << min(monA,monB) << endl;
  return 0;
}