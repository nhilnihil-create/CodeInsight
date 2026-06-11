#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int A,B;
    cin >> A >> B;

    if(B % A == 0) cout << A + B;
    else cout << B - A;
   return 0;
}