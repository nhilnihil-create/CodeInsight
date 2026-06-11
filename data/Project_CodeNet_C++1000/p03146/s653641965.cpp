#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int f(int x) {
    if (x%2 == 0) {
        return x/2;
    }
    return 3*x + 1;
}

int main() 
{
    int n;
    cin >> n;

    set<int> S;
    rep(i,1000000) {
        if (S.find(n) != S.end()) {
            cout << i+1 << endl;
            return 0;
        }
        S.insert(n);
        n = f(n);
    }
    return 0;
}
