#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

   int a[3];
   cin >> a[0] >> a[1] >> a[2];
   sort(a, a + 3);

   int step = a[2] - a[1];
   a[0] += step;

   if((a[2] - a[0]) % 2 == 0)
     step += (a[2] - a[0]) / 2; 
   else
     step += (a[2] - a[0] + 1) / 2 + 1;
   
   cout << step;
   
   return 0;
}
