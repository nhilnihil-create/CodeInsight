#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  int S= 0;
  for(int i = N ; i <= K ; i++){
    int r = i;
    int a, b, c, d, e;
    a = r / 10000;
    r = r % 10000;
    b = r / 1000;
    r = r % 1000;
    c = r / 100;
    r = r % 100;
    d = r / 10;
    e = r % 10;
    if( (a == e) && (b == d)){
      S++;
    //cout << a << " " << b << " " << c << " " << d << " " << e << endl;
    }
  }
  cout << S << endl;
}
