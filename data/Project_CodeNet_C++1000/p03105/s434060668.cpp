#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int a,b,c;
  cin >> a >> b >>c;
  int cnt;
  while(b >= a){
    cnt++;
    b-=a;
    if(cnt == c) break;
  }
cout << cnt << endl;
}
  
