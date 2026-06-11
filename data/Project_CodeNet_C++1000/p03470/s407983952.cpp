#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,i,x;
  x = 0;
  cin >> N;
  vector<int> a(N);
  for(i=0;i<N;i++) cin >> a.at(i);
  sort(a.begin(), a.end());
  if(N == 1) cout << 1 << endl;
  else{
   for(i=0;i<N-1;i++){
    if(a.at(i) == a.at(i+1)) x = x + 1;
   }
   cout << N-x << endl;
  }
}




