#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main() 
{
    int r, D, x;
    cin >> r >> D >> x;

    int X[11];
    X[0] = x;

    for(int i=1; i<=10; i++) {
        X[i] = r*X[i-1] - D;
    }

    for(int j=1; j<=10; j++) {
        cout << X[j] << endl;
    }
    return 0;
}
