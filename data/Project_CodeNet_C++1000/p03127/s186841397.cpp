#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b == 0){
        return a;
    }

    return gcd(b, a%b);
}

int main(){

    int n;
    cin >> n;

    int a;
    cin >> a;
    
    for (int i = 0; i<n; i++){
        int b;
        cin >> b;

        a = gcd(a, b);
    }

    cout << a << endl;
}