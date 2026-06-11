#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ld long double
//初期化
#define DEFO(n) lli n = 0;
//整数最大
#define MAX(n) lli n = 9000000000000000000;
//整数最小
#define MIN(n) lli n = -9000000000000000000;
//少数最大
#define MAX_D(n) ld n = 4500;
//少数最小
#define MIN_D(n) ld n = -4500;
//整数入力
#define LLI(n) \
  lli n;       \
  cin >> n;
//少数入力
#define LD(n) \
  ld n;       \
  cin > n;
//整数配列入力
#define LLIV(a, n)            \
  vector<lli> a(n);           \
  for (lli i = 0; i < n; i++) \
  {                           \
    cin >> a.at(i);           \
  };
//２列整数配列入力
#define LLIV2(a, b, n)         \
  vector<lli> a(n), b(n);      \
  for (lli i = 0; i < n; i++)  \
  {                            \
    cin >> a.at(i) >> b.at(i); \
  };
//３列整数配列入力
#define LLIV3(a, b, c, n)                 \
  vector<lli> a(n), b(n), c(n);           \
  for (lli i = 0; i < n; i++)             \
  {                                       \
    cin >> a.at(i) >> b.at(i) >> c.at(i); \
  };
//少数配列入力
#define LDV(a, n)             \
  vector<ld> a(n);            \
  for (lli i = 0; i < n; i++) \
  {                           \
    cin >> a.at(i);           \
  };
//文字列入力
#define STR(n) \
  string n;    \
  cin >> n;
//文字列配列入力
#define STRV(a, n)            \
  vector<string> a(n);        \
  for (lli i = 0; i < n; i++) \
  {                           \
    cin >> a.at(i);           \
  };
//配列の合計
#define SUM(n) accumulate(n.begin(), n.end(), 0);
//配列を昇順
#define SORT(n) sort(n.begin(), n.end());
//配列を降順
#define REVE(n) reverse(n.begin(), n.end());
//Yesと表示
#define yes              \
  cout << "Yes" << endl; \
  return 0;
//Noと表示
#define no              \
  cout << "No" << endl; \
  return 0;
//Noneと表示
#define none              \
  cout << "None" << endl; \
  return 0;
//四捨五入
#define C45(n) (n + 1) / 2
//nを出力
#define OUT(n) cout << n << endl;
//文字列からcを探す
#define SRC(n, c)                    \
  for (lli i = 0; i < s.size(); i++) \
  {                                  \
    if (s.at(i) == c)                \
    {                                \
      n++;                           \
    }                                \
  };

//素数
bool IsPrime(lli num)
{
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;
  long double sqrtNum = sqrt(num);
  for (lli i = 3; i <= sqrtNum; i += 2)
  {
    if (num % i == 0)
      return false;
  }
  return true;
}
//各桁の和
lli KSum(lli n)
{
  lli sum = 0;
  if (n < 0)
    return 0;
  while (n > 0)
  {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

//数値反転
bool KReve(lli n)
{
  int reverse = 0;
  int remaind;
  int tmp = n;
  while (tmp != 0)
  {
    remaind = tmp % 10;
    reverse = reverse * 10 + remaind;
    tmp /= 10;
  }
  if (reverse == n)
    return true;
  else
    return false;
}

int main(void)
{
  ios::sync_with_stdio(false);
  LLI(a)LLI(b)LLI(c)LLI(x)LLI(y)DEFO(ans)
  lli z = min(x, y);
  lli w = a * x +  b * y;
  lli q = c * z * 2 + a * (x - z) + b * (y - z);
  lli s = c * max(x, y) * 2;
  ans = min(w, q);
  ans = min(ans, s);
  OUT(ans)
}
