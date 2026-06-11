#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long count =0;
  for(int i=1; i<=sqrt(N); i++){
    long long syou = N/i;
    if(N%i==0 && syou>2 && i<syou-1)count += syou-1;
  }
  
  cout << count << endl;
  
}