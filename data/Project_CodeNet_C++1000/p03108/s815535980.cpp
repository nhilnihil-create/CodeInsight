#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define MOD 998244353
#define INIT -1

class UF
{
private:
   int n;
   vector<int> root;
   vector<int> size;

public:
   UF(int k)
   {
      n = k;
      root = vector<int>(n, -1);
      size = vector<int>(n, 1);
   }
   int getRoot(int x)
   {
      if (root[x] == -1)
         return x;
      else
         return root[x] = getRoot(root[x]);
   }
   void connect(int x, int y)
   {
      x = getRoot(x);
      y = getRoot(y);
      if (x == y)
         return;
      if (y < x)
         swap(x, y);
      root[y] = x;
      size[x] += size[y];
   }
   int getSize(int x)
   {
      return size[getRoot(x)];
   }
};

int main()
{
   long long int n, m;
   cin >> n >> m;
   vector<pair<int, int>> v;
   for (int i = 0; i < m; i++)
   {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      v.push_back(make_pair(a, b));
   }
   vector<long long int> ans;
   long long int nowans = n * (n - 1) / 2;
   ans.push_back(nowans);
   UF uf(n);
   for (int i = m - 1; i > 0; i--)
   {
      int a = v[i].first;
      int b = v[i].second;
      a = uf.getRoot(a);
      b = uf.getRoot(b);
      if (a != b)
      {
         long long int asize = uf.getSize(a);
         long long int bsize = uf.getSize(b);
         nowans -= asize * bsize;
         uf.connect(a, b);
      }
      ans.push_back(nowans);
   }
   for (auto itr = ans.rbegin(); itr != ans.rend(); itr++)
   {
      cout << *itr << endl;
   }
}