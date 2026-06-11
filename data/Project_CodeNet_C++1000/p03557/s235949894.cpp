#include <bits/stdc++.h>
using namespace std;

int main() {
   int N;
   cin >> N;
   int A[N],B[N],C[N];
   for (int i=0; i<N; i++) {
      cin >> A[i];
   }
   for (int i=0; i<N; i++) {
      cin >> B[i];
   }
   for (int i=0; i<N; i++) {
      cin >> C[i];
   }
   sort(A,A+N);
   sort(B,B+N);
   sort(C,C+N);
   long long total=0;
   for (int i=0; i<N; i++) {
      long long counta=0,countc=0;
      counta=lower_bound(A,A+N,B[i])-A;
      if (B[i]<C[N-1]) countc=N-(upper_bound(C,C+N,B[i])-C);
      total+=counta*countc;
   }
   cout << total << endl;
}
