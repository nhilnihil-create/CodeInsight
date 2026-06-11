#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
    cin >> a >> b;
  int t = (a + b) % 2;
  double q = (a + b) / 2;
  if (t == 1){
    cout << q + 1 << endl;
  }
    else if(t == 0){
  cout << q << endl;
    }
}