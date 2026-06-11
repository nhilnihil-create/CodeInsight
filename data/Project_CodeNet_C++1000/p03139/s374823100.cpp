#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  int maxx = min({A, B});
  int minn = max(A + B - N, 0);
  cout << maxx << ' ' << minn << endl;
}