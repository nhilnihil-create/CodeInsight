#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum=0;
  cin >> N;
  
  if(N % 10 ==2) sum++;  
  if(N /10 %10 ==2) sum++;
  if(N /100 %10 ==2) sum++;
  if(N /1000 %10 ==2) sum++;
  
  cout << sum << endl;
}
