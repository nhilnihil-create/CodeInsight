#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b, sum, mult, sub, maxv;
    cin >> a >> b;

    sum = a + b;
    sub = a - b;
    mult = a * b;
    maxv = max(sum, sub);
    maxv = max(maxv, mult);
    cout << maxv << endl;

    return 0;
}