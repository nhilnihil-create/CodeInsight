#include <bits/stdc++.h>
using namespace std;
int main(){
  long long K, A, B;
  cin >> K >> A >> B;
  if (B <= A + 1){
    cout << K + 1 << endl;
  } else if (K <= A){
    cout << K + 1 << endl;
  } else {
    cout << A + (K - A + 1) / 2 * (B - A) + (K - A + 1) % 2 << endl;
  }
}