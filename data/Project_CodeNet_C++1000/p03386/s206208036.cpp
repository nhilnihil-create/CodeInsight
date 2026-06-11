#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef long double ld;

int INF = 100100101;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a,b,k;
  cin >> a >> b >> k;
  int count = 0;
  for(int i = a; i <= b; i++){
    if(count++ < k) cout << i << endl;
    else if(b - i < k) cout << i << endl; 
  }
  return 0;
}