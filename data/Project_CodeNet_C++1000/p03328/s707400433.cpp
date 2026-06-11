#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int a,b;
  cin >> a >> b;
  int n =  b-a;
  int tall = 0;
  for(int i = 0; i <= n; i++){
    tall += i;
  }
  int x = tall - b;
  cout << x << endl;
  return 0;
}