#include<bits/stdc++.h>
using namespace std;

int main(){
  int N[4];
  bool flag[4];
  for(int i=0; i<4; i++){
    cin >> N[i];
    if(N[i]==1) flag[0]=true;
    if(N[i]==9) flag[1]=true;
    if(N[i]==7) flag[2]=true;
    if(N[i]==4) flag[3]=true;
  }
  for(int i=0; i<4; i++){
    if(!flag[i]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}