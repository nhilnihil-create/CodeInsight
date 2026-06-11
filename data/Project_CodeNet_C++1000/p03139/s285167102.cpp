#include <bits/stdc++.h>
using namespace std;

int main() {
   int N, A, B;
   scanf("%d %d %d", &N, &A, &B);
   printf("%d %d\n", min(A, B), max(0, (A + B) - N));
   return 0;
}//main
