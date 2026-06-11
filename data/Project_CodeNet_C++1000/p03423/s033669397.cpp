#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  if (n%3==1) {
    cout<< (n-1)/3 <<endl;
  }
  else if (n%3==2) {
    cout<< (n-2)/3 << endl;
  }
  else{
    cout << n/3 << endl;
  }
}
