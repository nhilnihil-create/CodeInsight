#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, unknown, X;
  cin >> A >> unknown >> X;

  string ans= (A <= X && X <= A+ unknown) ? "YES"
                                          : "NO";

  cout << ans << endl;
}