#include<bits/stdc++.h>
using namespace std;

#define N 4
#define M 3

int main(void){
  int i,L[N];
  pair <int, int> path;
  string ans="YES";
  for(i=0;i<N;i++)L[i]=0;
  for(i=0;i<M;i++){
    cin >> path.first >> path.second;
    L[path.first-1]++;
    L[path.second-1]++;
  }
  for(i=0;i<N;i++){
    if(L[i] > 2 )ans="NO";
  }
  cout << ans << endl;

  return 0;
}