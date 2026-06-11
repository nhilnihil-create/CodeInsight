#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int a,sum = 0;
  cin >> a;
  int jwe[a],wor[a];
  for(int i = 0;i<a;i++){
    cin >> jwe[i];
  }
  for(int i = 0;i<a;i++){
    cin >> wor[i];
  }
  for(int i = 0;i<a;i++){
    sum += max(jwe[i]-wor[i],0);
  }
  cout << sum;
}