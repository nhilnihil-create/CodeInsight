#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  for(int64_t h=1; h<=3500; h++)
  for(int64_t n=h; n<=3500; n++)
    if(4*h*n-N*h-N*n>0 && N*h*n%(4*h*n-N*h-N*n)==0){
      cout << h << " " << n << " "<< N*h*n/(4*h*n-N*h-N*n);
      return 0;
    }
  return 0;
}