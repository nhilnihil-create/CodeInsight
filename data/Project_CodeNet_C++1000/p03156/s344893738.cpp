#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int A, B, N;

   cin >> N >> A >> B;

   vector<int> P(N);

   int count_L = 0, count_M = 0, count_H = 0;

   for (int i = 0; i < N; i++) {
     cin >> P.at(i);
     if (P.at(i) <= A) count_L++;
     else if (P.at(i) > B) count_H++;
     else count_M++;
   }

   cout << min(count_L, min(count_M, count_H)) << endl;
 }
