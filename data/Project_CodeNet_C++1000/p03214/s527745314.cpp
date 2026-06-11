#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int N, sum_a = 0;
   double average;
   cin >> N;
   vector<int> a(N);
   for (int i = 0; i < N; i++) {
     cin >> a.at(i);
     sum_a += a.at(i);
   }
   average = (sum_a * 1.0) / (N * 1.0);

   double min_ave = 100;
   int ans;

   for (int i = 0; i < N; i++) {
     if (fabs(a.at(i) - average) < min_ave) {
       min_ave = fabs(a.at(i) - average);
       ans = i;
     }
   }
   cout << ans << endl;
 }
