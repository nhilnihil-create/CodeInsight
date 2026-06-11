#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

int a[101];
int b[101];

int main()
{
 	int n, m, x;
  	cin >> n >> m >> x;
  	for (int i = 1; i <= m; ++i)
    {
      cin >> a[i];
      b[a[i]] = 1;
    }
    int y = x;
    int c = 0;
  	while (y > 0)
    {
     	y -= 1;
      	if (b[y] == 1)
          c++;
    }
  	int d = 0;
  	while (x < n+1)
    {
     	x += 1;
      	if (b[x] == 1)
          d++;
    }
    cout << min(c, d);
}