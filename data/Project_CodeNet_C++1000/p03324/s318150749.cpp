#include <bits/stdc++.h>
using namespace std;

int main()
{
      int D, N; cin >> D >> N;
      int c = (N == 100) ? 1 : 0;
      int a = (N + c) * pow(100, D);
      cout <<  a; return 0;
}