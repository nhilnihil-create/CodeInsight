#include <bits/stdc++.h>
using namespace std;
 
int n, k, a=1;
 
int main () {
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        if (a+k<2*a) {
          a += k;
        }else{
          a *= 2;
          }
    }
    cout << a << endl;
}