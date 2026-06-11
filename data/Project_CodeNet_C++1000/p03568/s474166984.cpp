#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long total=1;
  int odd=1;
  for (int i=0;i<n;i++){
    total*=3;
    int num;
    cin >> num;
    if (num%2==0) odd*=2;
  }
  cout << total-odd << endl;
}