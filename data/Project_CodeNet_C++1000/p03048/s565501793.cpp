#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int sum = 0;
  rep(i, 3001){
    rep(j, 3001){
      if(n == i*r+j*g) sum++;
      if(n > i*r+j*g){
      	if((n-(i*r+j*g)) % b == 0) sum++;
      }
    }
  }
  cout << sum << endl;
  return 0;
}