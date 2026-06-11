#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
/* global variables */
/* function */
/* main */
int main(){
    int a, b;
    cin >> a >> b;
    if (a + b == 15) cout << '+' << '\n';
    else if (a * b == 15) cout << '*' << '\n';
    else cout << 'x' << '\n';
}