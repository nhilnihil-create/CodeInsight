#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a, b, c, k;
    cin >> a >> b >> c >> k;

    if(k % 2 == 0) cout << a - b << endl;
    if(k % 2 == 1) cout << b - a << endl;
    return 0;
}