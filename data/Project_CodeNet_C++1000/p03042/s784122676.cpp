#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    bool yy = false,mm = false;
    if(s[0] == '0' && s[1] != '0' || s[0] == '1' && s[1] == '0' || s[0] == '1' && s[1] == '1' || s[0] == '1' && s[1] == '2'){
        mm = true;
    }
    if(s[2] == '0' && s[3] != '0' || s[2] == '1' && s[3] == '0' || s[2] == '1' && s[3] == '1' || s[2] == '1' && s[3] == '2'){
        yy = true;
    }
    if(yy && mm) cout << "AMBIGUOUS" << endl;
    else if(!yy && mm) cout << "MMYY" <<endl;
    else if(yy && !mm) cout << "YYMM" << endl;
    else cout << "NA" << endl;
    
    return 0;
}