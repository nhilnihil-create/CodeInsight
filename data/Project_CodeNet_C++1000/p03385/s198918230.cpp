#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (INT_MAX / 4)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define TIMER_S(start) chrono::system_clock::time_point start = chrono::system_clock::now();
#define TIMER_E(end) chrono::system_clock::time_point end = chrono::system_clock::now();
#define TIME(start, end) cout << static_cast<double>(chrono::duration_cast<chrono::microseconds>(end - start).count()) << "ms" \
                              << "\n";

int main()
{
string s;
  cin>>s;
  if(s.at(0)+s.at(1)+s.at(2)=='a'+'b'+'c')cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
    return 0;
}
