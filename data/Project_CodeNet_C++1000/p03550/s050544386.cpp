#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
ll MOD = 1000000007;
const int mod = 1000000007;
ll INF = 1LL << 60;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
   for (auto &v : vec)
      is >> v;
   return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
   os << "[";
   for (auto v : vec)
      os << v << ",";
   os << "]";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec)
{
   os << "deq[";
   for (auto v : vec)
      os << v << ",";
   os << "]";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec)
{
   os << "{";
   for (auto v : vec)
      os << v << ",";
   os << "}";
   return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
   os << "(" << pa.first << "," << pa.second << ")";
   return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp)
{
   os << "{";
   for (auto v : mp)
      os << v.first << "=>" << v.second << ",";
   os << "}";
   return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp)
{
   os << "{";
   for (auto v : mp)
      os << v.first << "=>" << v.second << ",";
   os << "}";
   return os;
}
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val)
{
   fill((T *)array, (T *)(array + N), val);
}

int a[2020],dp[2020][2];
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n , z , w;
   cin >> n >> z >> w;
   for(int i=0; i < n; i++)
      cin >> a[i];

   int ans = 0;
   ans = abs(a[n-1] - w);
   if(n > 1){
      ans = max(ans, abs(a[n - 2] - a[n - 1]));
   }
   cout << ans << endl;

}