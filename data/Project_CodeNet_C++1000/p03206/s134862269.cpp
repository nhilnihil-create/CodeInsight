#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int D;

int main(){
  cin >> D;
  switch (D){
    case 22:
      cout << "Christmas Eve Eve Eve" << endl;
      break;
    case 23:
      cout << "Christmas Eve Eve" << endl;
      break;
    case 24:
      cout << "Christmas Eve" << endl;
      break;
    case 25:
      cout << "Christmas" << endl;
      break;
  }
}
