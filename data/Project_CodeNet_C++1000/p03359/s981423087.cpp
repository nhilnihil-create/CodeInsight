#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 100100100;
using namespace std;

int main()
{
  int a, b;
  int res=0;
  cin >> a >> b;

  for(int i=1;i<=a;i++){
    if(i==a && b < a) break;
    res++;
  }

  cout << res << endl;
}