#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int maxn = (1 << 18);

int N, a[maxn], mx[maxn];

pair<int, int> p[maxn];

void modify(pair<int, int> &x, pair<int, int> y)
{
   /// y.first
   if(a[x.first] < a[y.first])
   {
      x.second = x.first;
      x.first = y.first;
   }
   else if((x.second == -1 || a[x.second] < a[y.first]) && x.first != y.first)
   {
      x.second = y.first;
   }
   /// y.second
   if(y.second == -1) return;
   if(a[x.first] < a[y.second])
   {
      x.second = x.first;
      x.first = y.second;
   }
   else if((x.second == -1 || a[x.second] < a[y.second]) && x.first != y.second)
   {
      x.second = y.second;
   }
}

int32_t main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
   cin >> N;
   for(int i = 0; i < (1 << N); i++) 
   {
      cin >> a[i];
      p[i] = {i, -1};
   }
   for(int i = 1; i < (1 << N); i++)
   {
      for(int j = 0; j < N; j++)
      {
         if(i >> j & 1)
         {
            modify(p[i], p[i ^ (1 << j)]);
         }
      }
   }
   for(int i = 1; i < (1 << N); i++)
   {
      mx[i] = max(mx[i - 1], a[p[i].first] + a[p[i].second]);
      cout << mx[i] << '\n';
   }
}