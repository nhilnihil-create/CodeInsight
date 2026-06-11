#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, a, b;
  cin >> t >> a >> b;

  int ta = t * a;

  if (ta > b) {
    cout << b << endl;
  }else if(ta < b){
    cout << ta << endl;
  }else{
    cout << b << endl;
  }
}
