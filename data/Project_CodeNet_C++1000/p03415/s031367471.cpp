#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    cout << s1[0] << s2[1] << s3[2] << endl;
    return 0;
}