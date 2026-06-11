#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   int D, N;
   cin >> D >> N;
   int x = pow(100, D);
   if(N == 100) N++;
   cout << x * N << endl;
}