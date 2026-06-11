#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2000;
const int M = N*N + 2;
int A[N];

void solve() {
   int n;
   scanf("%d",&n);
   int sum = 0;
   bitset<M> s;
   s[0]= 1;
   for(int i=0;i<n;++i) {
      scanf("%d",&A[i]);
      sum += A[i];
      s |= (s<<A[i]);
   }
   sum= (sum+1)/2;
   for(int i= sum;i<M;++i) {
      if(s[i]==1) {
         printf("%d\n", i);
         break;
      }
   }
   
}
int main() {
   //freopen("input.txt","r",stdin);
   solve();
}