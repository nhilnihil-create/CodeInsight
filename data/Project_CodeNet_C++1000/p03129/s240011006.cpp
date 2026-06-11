#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, K;
   scanf("%d %d", &N, &K);
   if (N / 2 + (N % 2 == 1) >= K)
      puts("YES");
   else
      puts("NO");
   return 0;
}//main
