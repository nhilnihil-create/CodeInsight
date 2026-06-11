#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int a, b;
  cin >> a >> b;
  int flag = 0;

  if(a == b){
    cout << b;
  }
  else if(a>b){
    cout << a - 1;
  }
  else{
    cout << a;
  }
}
