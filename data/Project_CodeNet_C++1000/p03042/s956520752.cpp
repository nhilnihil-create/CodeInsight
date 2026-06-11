#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a = N/100;
  int b = N%100;
  int A = 0;
  int B = 0;
  if (1 <= a && 12 >= a)
    A++;
  if (1 <= b && 12 >= b)
    B++;
  
  if (B == 0 && A == 0)
    cout << "NA" << endl;
  if (A == 1 && B == 1)
    cout << "AMBIGUOUS" << endl;
  if (A == 1 && B == 0)
    cout << "MMYY" << endl;
  if (A == 0 && B == 1) 
    cout << "YYMM" << endl;
  
}