#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <set>
#include <map>
#include <list>
#include <cstdlib>

using namespace std;

#define mod (1e9 + 7)
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()

typedef long long ll;

void solve1()
{
   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;

   int diffx = x1-x2;
   int diffy = y1-y2;

   cout << x2 + diffy << " " << y2 - diffx << " ";
   cout << x2 + diffy + diffx << " " << y2 - diffx + diffy << endl;
}

int main()
{
   solve1();
}