#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >>s;
    if(s[5] == '1'){
        cout << "TBD" << endl;
        return 0;
    }else if(s[6] <= '4'){
        cout << "Heisei" << endl;
    }else{
        cout << "TBD" << endl;
    }
    return 0;
}