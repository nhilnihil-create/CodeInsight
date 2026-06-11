#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int d[10];
  for(int i = 1; i<=4; i++) d[i]=0;
  for(int i = 0; i<6; i++){
    int z;
    cin >>z;
    d[z]++;
  }
  if(d[1]<=2 && d[2]<=2 && d[3]<=2 && d[4]<=2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}