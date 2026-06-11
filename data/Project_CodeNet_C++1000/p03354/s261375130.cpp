#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e6;
int unip[max_n],unir[max_n];
void init(int n){
  for(int i=0 ; i<n ; i++){
    unip[i] = i;
    unir[i] = 0;
  }
}
int find(int x){
  if(unip[x] == x){
    return x;
  }else{
    return unip[x] = find(unip[x]);
  }
}
void unite(int x, int y){
  x = find(x);  y = find(y);
  if(unip[x] == unip[y]){
    return;
  }
  if(unir[x] < unir[y]){
    unip[x] = y;
  }else{
    unip[y] = x;
    if(unir[x] == unir[y]){
      unir[x]++;
    }
  }
}
bool same(int x, int y){
  return find(x) == find(y);
}
int main(){
  int n,m;
  cin >> n >> m;
  int p[n];
  init(n);
  for(int i=0 ; i<n ; i++){
    cin >> p[i];
    --p[i];
  }
  int x[m], y[m];
  for(int i=0 ; i<m ; i++){
    cin >> x[i] >> y[i];
    --x[i]; --y[i];
    unite(x[i], y[i]);
  }
  int count = 0;
  for(int i=0 ; i<n ; i++){
    if(same(p[i],i)){
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
