#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, B, x;
  cin >> N >> A >> B;
  //500円で払える分だけ払う
  if (N * A < B) {
    x = N * A;
  }else if(N * A > B){
  	x = B;
  }else{
  	x = x;
  }
  cout << x << endl;
}