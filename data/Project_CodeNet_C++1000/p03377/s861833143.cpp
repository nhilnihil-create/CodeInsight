#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  if(a>c){
    cout << "NO";
    return 0;
  }

  if(b>= c-a){
    cout << "YES";
  }
  else
  {
    cout << "NO";
  }

}
