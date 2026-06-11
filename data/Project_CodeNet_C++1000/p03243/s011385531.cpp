#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int N;

int main(){
  cin >> N;
  repi(i, N, 1000){
    if (i%10 == (i/10)%10 && (i/10)%10 == (i/100)%10){
      cout << i << endl;
      break;
    }
  }
}
