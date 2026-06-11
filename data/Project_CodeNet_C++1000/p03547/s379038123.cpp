#include <bits/stdc++.h>
using namespace std;
int main() {
  char A, B;
  cin >> A >> B;
  if(A < B) {
    cout << "<" << endl;
  }
  if(A == B) {
    cout << "=" << endl;
  }
  if(A > B) {
    cout << ">" << endl;
  }
}
