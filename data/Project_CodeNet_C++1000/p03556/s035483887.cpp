#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N;
  cin >> N;
   for (long long i=1;i<100000;i++) {if (i*i<=N && (i+1)*(i+1)>N) {cout << i*i << endl;}} 
}
