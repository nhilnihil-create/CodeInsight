#include<bits/stdc++.h>
using namespace std;

int saisho(int a, int b)
{
  int keta_a, keta_b;
  keta_a = 0;
  keta_b = 0;
  while(a>0)
  {
    keta_a += a%10;
    a /= 10;
  }
   while(b>0)
  {
    keta_b += b%10;
    b /= 10;
  }
  return keta_a + keta_b;
}

int main()
{
  int n, i, sum, ans, amari;
  ans = INT_MAX;
  cin >> n;
  for(i=1; i<n; i++)
  {
    amari = n-i;
    sum = saisho(i, amari);
    if(sum < ans) ans = sum;
  }
  cout << ans << endl;
  return 0;
}