#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long a,b;
  cin >> a >> b;
  vector<long> h(1000);
  h[0]=0;
  for(long i=1;i<1000;i++) h[i]=h[i-1]+i;
  cout << h[b-a]-b << endl;
}