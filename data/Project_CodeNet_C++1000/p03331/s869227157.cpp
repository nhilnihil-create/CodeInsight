// include
// ------------------------------------------------
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// func
// ------------------------------------------------
int CalcSumOfDigit(int n);      // 各桁の和を計算する。

// define
// ------------------------------------------------
#define all(a)        (a).begin(),(a).end()
#define pb            push_back
#define sz(a)         int((a).size())
#define rep(i,n)      for(int(i)=0;(i)<(n);(i)++)
#define repe(i,n)     for(int(i)=0;(i)<=(n);(i)++)
#define vsort(v)      sort((v).begin(),(v).end())

const int INF = 1e9;


// code
// ------------------------------------------------
int main() {
  int n,b;

  cin >> n;

  int min = INF;
  for(int a = 1; a <= n / 2; a++)
  {
    b = n - a;
    int buf = CalcSumOfDigit(a) + CalcSumOfDigit(b);
    if(buf < min)
      min = buf;
  }

  cout << min << endl;
  return 0;
}

// funcの実体
// ------------------------------------------------
int CalcSumOfDigit(int n)
{
  int s = 0;
  while(n)
  {
    s += n % 10;
    n = n / 10;
  }
  return s;
}