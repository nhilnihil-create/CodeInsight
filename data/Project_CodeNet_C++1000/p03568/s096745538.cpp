#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;

 int main() {
   int N;
   cin >> N;
   vector<int> A(N);
   int minus = 1;

   for (int i = 0; i < N; i++) {
     cin >> A.at(i);
     if (A.at(i)  % 2 == 0) minus *= 2;
   }

   cout << pow(3, N) - minus << endl;
 }
