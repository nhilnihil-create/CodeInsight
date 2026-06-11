#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <math.h>
using namespace std;

#define rep(i, o) for (int i = 0; i < (o); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)

#define F_H 500
#define O_H 100
#define F_T 50


typedef long long ll;


ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;

  int count = 0;
  for (int i = 0; i <= a; i++)
  {
      /* code */
      for(int j = 0; j <= b; j++)
      {
          /* code */
          for (int k = 0; k <= c; k++)
          {
              /* code */
              if (a > x) break;
              if (F_H * i + O_H * j + F_T * k == x) count++;
          }
      }
  }
  
  cout << count << endl;
  return 0;
}