#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int sum = 21;
  rep(i,4){
    int n;
    cin >>n;
    if(n==1 || n==9 || n==7 || n==4) sum -= n;
  }
  if(sum==0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}