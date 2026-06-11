#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A, B;
    cin >> N >> A >> B;
  	int X = A*N, Y = B;
    if (X>=Y) cout << Y << endl;
    else cout << X << endl;
}