#include <bits/stdc++.h>

using namespace std;

void fast()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
}
int gcd(int a, int b) {
   if (b == 0)
      return a;
   return gcd(b, a % b);
}
const int mxA = 1e7;
int freq [mxA+1] ;
int pref [mxA+1];

int main()
{
    fast();
    int n ,x;
    cin >> n >>x;
     cout << (n-1) * (x-1) ;
}

