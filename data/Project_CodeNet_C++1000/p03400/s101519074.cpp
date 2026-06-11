#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,d,x;
  cin >> n >> d >> x;
  rep(i,0,n){
    int a,v = 1;
    cin >> a;
    while(v <= d){
      x++;
      v += a;
    }
  }
  cout << x << endl;
}