#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int a[1 + nmax], b[1 + nmax];

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> a[i];
  for(int i = 1;i <= n; i++)
    cin >> b[i];

  ll sum = 0;
  for(int i = 1;i <= n; i++)
    sum += b[i] - a[i];

  ll op1 = 0, op2 = 0;
  for(int i = 1;i <= n; i++){
    if(b[i] < a[i])
      op1 += a[i] - b[i];
    else if(a[i] < b[i]){
      int dif = b[i] - a[i];
      if(dif % 2 == 1)
        op1++;
      op2 += (dif + 1) / 2;
    }
  }

  if(op1 <= sum && op2 <= sum)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
