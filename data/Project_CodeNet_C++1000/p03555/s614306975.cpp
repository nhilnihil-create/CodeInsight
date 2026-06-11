#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using namespace std;
int main(){
  char a[3];
  rep(i, 3) cin >> a[i];
  rep(i, 3){
    char b;
    cin >> b;
    if(b != a[2 - i]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}