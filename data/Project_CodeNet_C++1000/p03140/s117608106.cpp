#include <bits/stdc++.h>
using namespace std;

set<char> S[101];
char A[110], B[110], C[110];

int main() {
   int N;
   int res = 0;
   scanf("%d", &N);
   scanf("%s %s %s", A, B, C);
   for (int i = 0; i < N; i++) {
      S[i].insert(A[i]);
      S[i].insert(B[i]);
      S[i].insert(C[i]);
      res += (int)S[i].size() - 1;
   }//for
   printf("%d\n", res);
   return 0;
}//main
