#include "bits/stdc++.h"
using ll = long long;
using namespace std;

const double pi = acos(-1);

pair <double, double> rotate(int x, int y, int degree, double d) {
   double theta = (2 * pi / 360) * degree;
   double x_ = x * cos (theta) - y * sin(theta);
   double y_ = x * sin (theta) + y * cos(theta);
   x_ *= d;
   y_ *= d;
   return {x_, y_};
}

const double eps = 1e-3;

int near(double x) {
   for(int i = (int)(x - 2); i < (int)(x + 2); i++) {
      if(abs(i - x) < eps) {
         return i;
      }
   }
   return 0;
}
void solve() {
   double x1, x2, y1, y2;
   cin >> x1 >> y1 >> x2 >> y2;

   int x = x2 - x1;
   int y = y2 - y1;

   auto p3 = rotate(x, y, 45, sqrt(2));
   auto p4 = rotate(x, y, 90, 1);

   double x3 = p3.first + x1;
   double y3 = p3.second + y1;

   double x4 = p4.first + x1;
   double y4 = p4.second + y1;

   cout << fixed << setprecision(3) << endl;
   cout << near(x3) << " " << near(y3) << " " << near(x4) << " " << near(y4) << endl;
}

int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   int testcase = 1;
   // cin >> testcase;

   for(int i = 0; i < testcase; i++) {
      solve();
   } 
   return 0;
}
