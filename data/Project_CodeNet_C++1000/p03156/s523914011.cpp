#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  vector<int> question_count(3, 0);
  rep(i, N)
  {
    int P;
    cin >> P;
    if (P < A + 1)
      question_count[0]++;
    else if (P < B + 1)
      question_count[1]++;
    else
      question_count[2]++;
  }
  int ans = min({question_count[0], question_count[1], question_count[2]});
  cout << ans << endl;
  return 0;
}