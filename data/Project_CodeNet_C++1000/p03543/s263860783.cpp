#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a1,a2,a3,a4;
  cin >> n;
  a1=n/1000;
  a2=(n/100)%10;
  a3=(n/10)%10;
  a4=n%10;
  if ( a2==a3 && (a1==a2 || a3==a4) ){
    cout << "Yes" << endl;
  } else {
	cout << "No" << endl;
  }
}
