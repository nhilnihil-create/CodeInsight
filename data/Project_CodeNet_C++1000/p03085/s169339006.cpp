#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    char x;
    cin >> x;
    if(x == 'A') cout << "T" << endl;
    if(x == 'C') cout << "G" << endl;
    if(x == 'G') cout << "C" << endl;
    if(x == 'T') cout << "A" << endl;

    return 0;
}