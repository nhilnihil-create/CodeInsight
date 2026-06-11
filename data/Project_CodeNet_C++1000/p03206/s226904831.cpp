#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int d;
    cin >> d;
    if(d == 25) cout << "Christmas"<<endl;
    if(d == 24) cout << "Christmas Eve"<<endl;
    if(d == 23) cout << "Christmas Eve Eve"<<endl;
    if(d == 22) cout << "Christmas Eve Eve Eve" <<endl;

    return 0;
}