#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  string op;
  cin >> N >> A;
if ( N - N / 1000 * 1000 == A )
  cout << "Yes" << endl;
if ( N - N / 1000 * 1000 > A ) {
  cout<< "No"<< endl;
 }
else if ( N - N / 1000 * 1000 < A ) {
  cout <<"Yes"<< endl;
 }
}