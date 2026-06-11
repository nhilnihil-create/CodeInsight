#include<bits/stdc++.h>
using namespace std;

int main(){
  int city[4]={};
  for(int i=0; i<3; i++){
    int a, b; cin >> a >> b;
    city[a-1]++;
    city[b-1]++;
  }
  for(int i=0; i<4; i++){
    if(city[i]==0 || city[i]>=3){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}