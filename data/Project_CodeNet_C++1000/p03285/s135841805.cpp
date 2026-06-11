#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a=N/7;
  string s="No";
  for(int i=0;i<a+1;i++){
    if((N-i*7)%4==0) s="Yes";
  }
  cout << s <<endl;
}
