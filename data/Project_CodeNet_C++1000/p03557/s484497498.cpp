#define _GLIBCXX_DEBUG
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
      //counta=lower_bound(A,A+N,B[i])-A;
      int low=0,high=N-1;
      if (A[0]<B[i] && A[N-1]>=B[i]) {
      while (high-low>1) {
         if (A[(low+high)/2]<B[i]) low=(low+high)/2;
         else high=(low+high)/2;
      }
      counta=high;
      }
      else if (A[N-1]<B[i]) counta=N;
      //if (B[i]<C[N-1]) countc=N-(upper_bound(C,C+N,B[i])-C);
      low=0,high=N-1;
      if (B[i]<C[N-1] && B[i]>=C[0]) {
      while (high-low>1) {
         if (C[(low+high)/2]>B[i]) high=(low+high)/2;
         else low=(low+high)/2;
      }
      countc=N-high;
      }
      else if (B[i]<C[0]) countc=N;
      total+=counta*countc;
   }
   cout << total << endl;
}