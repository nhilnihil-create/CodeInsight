#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int main(){
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll a,b,c;
  ll min = 10e16;
  for(c = 0; c <= 100000; c++){
    a = X - c;
    b = Y - c;
    if(a < 0) a = 0;
    if(b < 0) b = 0;
    if(a*A + b*B + 2*c*C < min) min = a*A + b*B + 2*c*C;
  }
  cout << min << endl;
}
