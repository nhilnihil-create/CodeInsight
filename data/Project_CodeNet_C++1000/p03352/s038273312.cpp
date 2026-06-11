#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  int N;
  cin >> N;
  for(double i=N;i>0;i--)
  {
    for(int j=0;j<32;j++)
    {
      if(pow(j,2)==i)
      {
        cout << i << endl;
        return 0;
      }
      if(pow(j,3)==i)
      {
        cout << i << endl;
        return 0;
      }
      if(pow(j,4)==i)
      {
        cout << i << endl;
        return 0;
      }
      if(pow(j,5)==i)
      {
        cout << i << endl;
        return 0;
      }
      if(pow(j,6)==i)
      {
        cout << i << endl;
        return 0;
      }
      if(pow(j,7)==i)
      {
        cout << i << endl;
        return 0;
      }
      if(pow(j,8)==i)
      {
        cout << i << endl;
        return 0;
      }
      if(pow(j,9)==i)
      {
        cout << i << endl;
        return 0;
      }
    }
  }
  return 0;
}
