#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, N;
  cin >> D >> N;
  
  int ans=1;
  while(D>0){
    ans *=100;
    D--;
  }
  if(N==100)N=101;
  cout << ans*N << endl;
}
