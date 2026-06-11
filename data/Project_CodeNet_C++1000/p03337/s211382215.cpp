#include <bits/stdc++.h>

using namespace std;


int main() {

    int a,b,soma, sub, prod, res;
    cin >> a;
    cin >> b;

    soma = a + b;
    sub = a - b;
    prod = a * b;
    
    if(soma > sub && soma > prod) {
        res = soma;
    }
    else if(sub > soma && sub > prod) {
        res = sub;
    }
    else if(prod > sub && prod > soma) {
        res = prod;
    }
    else if(soma == sub && soma == prod) {
        res = soma;
    }
        
    cout << res << '\n';

    return 0;
}

