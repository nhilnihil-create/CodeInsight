#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int i;
    cin >> i;
    int a = i/100, b = (i-100*a)/10, c = (i-100*a-10*b);
    cout << a + b + c;
}