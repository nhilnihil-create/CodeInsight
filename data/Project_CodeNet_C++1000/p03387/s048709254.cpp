#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    vector<int> X(3);
    cin >> X[0] >> X[1] >> X[2];
    
    sort(X.begin(),X.end());
    
    int a,b;
    
    a = X[2] - X[0];
    b = X[2] - X[1];
    
    a /= 2;
    b /= 2;
    
    //cout << a << " " << b << endl;
    
    int p,q;
    
    p = X[0] + a * 2;
    q = X[1] + b * 2;
    
    if ( 2 * X[2] - p - q == 2 ){
        cout << a + b + 1 << endl;
    } else if (2 * X[2] - p - q == 0 ){
        cout << a + b << endl;
    } else {
        cout << a + b + 2 << endl;
    }
    
    
    return 0;
}
