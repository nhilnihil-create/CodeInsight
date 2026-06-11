#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int m;
    if(n % 2 == 1) m = n * (n-1) / 2 - (n-1) / 2;
    if(n % 2 == 0) m = n * (n-2) / 2;

    int x;
    if(n % 2 == 1) x = n;
    if(n % 2 == 0) x = n + 1;

    cout << m << endl;
    for(int a=1; a<=n; a++){
        for(int b=a+1; b<=n; b++){
            if(a + b == x) continue;
            cout << a << " " << b << endl;
        }
    }
    return 0;
}