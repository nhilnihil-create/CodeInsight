#include <bits/stdc++.h>
using namespace std;

int main() {
   int N;
   cin >> N;
   int C[N-1],S[N-1],F[N-1];
   for (int i=0; i<N-1; i++) {
       cin >> C[i] >> S[i] >> F[i];
   }
   for (int i=0; i<N-1; i++) {
       int t=S[i];
       for (int j=i; j<N-1; j++) {
           if (t<S[j]) t=S[j];
           while (t%F[j]!=0) {
               t++;
           }
           t+=C[j];
       }
       cout << t << endl;
   }
   cout << 0 << endl;
}