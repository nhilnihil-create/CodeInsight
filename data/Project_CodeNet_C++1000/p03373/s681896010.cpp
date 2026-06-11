#include <bits/stdc++.h>
using namespace std;
int main(){
 int a, b, c, x, y;
 cin >> a >> b >> c >> x >> y;
 if(a + b <= 2 * c){cout << a * x + b  * y << endl;}
 else{
   int sum = c * 2 * min(x, y);
   int rem = max(x, y) - min(x, y);
   int val;
   (max(x, y) == x) ? val = a : val = b;
   if(val >= 2 * c) sum += rem * 2 * c;
   else sum += rem * val;
   cout << sum << endl;
 }
}