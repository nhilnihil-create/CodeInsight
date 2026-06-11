#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int abd = abs(a-b);
    int bcd = abs(b-c);
    int acd = abs(a-c);
    if(d >= acd){
        cout << "Yes" << endl;
        return 0;
    }
    if(d >= abd && d >= bcd){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}