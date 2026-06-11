#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
  int cnt = 0;
rep(i,4){
  char x;
  cin >> x;
  if(x=='2')cnt++;
}
cout << cnt << endl;
}
