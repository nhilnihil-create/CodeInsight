#include <bits/stdc++.h>
using namespace std;

string a;
int b=0;

int main () {
  cin >> a;
  for(int i=0; i<a.length(); i++){
    if (a[i] == '+') {
      b=b+1;
    } else if (a[i] == '-') {
      b=b-1;
    }
  }
  cout << b << endl;
}