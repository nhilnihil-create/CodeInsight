#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int a,b,T;
cin >> a >> b >> T;
int t = a,cnt = 0;
while(t < T + 0.5){
  cnt += b;
  t += a;
 
}
cout << cnt << endl;
}
  
