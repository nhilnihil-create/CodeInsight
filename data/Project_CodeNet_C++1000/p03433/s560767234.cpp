#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N, A,x,y,z;
    cin >> N >> A;
    x = N / 500;
    y = N - 500 * x;
    z = A - y;
    if (z >= 0){
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
}