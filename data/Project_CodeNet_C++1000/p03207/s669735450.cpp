#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,T;
  cin >> N;
  T=0;
  vector<long long> p(N);
  for (int i=0;i<N;i++) {cin >> p[i];}
  sort(p.begin(),p.end());
  for (int i=0;i<N-1;i++) {T+=p[i];}
  cout << T+p[N-1]/2 << endl;
  
}