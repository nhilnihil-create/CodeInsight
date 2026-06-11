#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A = 0;
  int N = 0;

  
  cin >> N >> A;

  if (N % 500 != 0){
	int r = 0;
    r = N % 500;
    if (r <= A){
    cout << "Yes" << endl;
    }
    else{
    cout << "No" << endl;
    }
  }
  else{
  cout << "Yes" << endl;
  }
}
