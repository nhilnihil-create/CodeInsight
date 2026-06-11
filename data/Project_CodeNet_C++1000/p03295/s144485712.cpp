#include <bits/stdc++.h>
using namespace std;

int main(){
  int Inf = 1000000;
  int n,m;
  cin >> n >> m;
  int c[100000+5];
   for (int i=0; i<n+5; i++){
    c[i+1] = Inf; 
  }
  for (int i=0; i<m; i++){
    int x,y;
    cin >> x >> y;
    c[x] = min(c[x], y); 
  }
  int i=1;
  int k=-1;
  int s=0;
  for (int i=1; i<=n; i++){
    if (c[i] == Inf){
      true;
    } else if(i < k){
      k = min(c[i],k);
    } else {
      s += 1;
      k = c[i];
    }
  }
  cout << s;
}