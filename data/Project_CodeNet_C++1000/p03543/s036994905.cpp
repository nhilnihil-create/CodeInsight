#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , a , b , c , d;
    cin >> n;

    a = n / 1000;
    n = n - a * 1000;
    b = n / 100;
    n = n - b * 100;
    c = n / 10;
    d = n % 10;

    if(a == b && b == c || b == c && c == d ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}