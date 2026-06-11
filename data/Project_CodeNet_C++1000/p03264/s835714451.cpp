#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int k;
    cin >> k;
    if(k%2 == 0) cout << k*k/4 << endl;
    else{
        int n = k/2;
        cout << n*(n+1) << endl;
    }
    return 0;
}