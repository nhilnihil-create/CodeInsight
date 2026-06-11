#include <bits/stdc++.h>

using namespace std; 
    
int main() {
    int a, b, c;
    int k; 

    cin >> a >> b >> c >> k;

    long long soma = 0;

    soma = a + b + c;

    int m = max(a, max(b, c));

    soma = soma - m; 

    soma = soma + m * pow(2, k);

    cout << soma << endl; 
}