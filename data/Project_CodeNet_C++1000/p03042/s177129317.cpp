#include<bits/stdc++.h>

using namespace std;
using ll = long long;



int main()
{
    string s; cin >> s;
    for(auto &i: s)i -= '0';
    int f = (s[0] * 10 + s[1]);
    int b = (s[2] * 10 + s[3]);
    // cout << f << b << endl;
    if(f == 0) {

        if(b == 0 || b > 12) cout << "NA" << endl;
        else cout << "YYMM" << endl;

    }else if(f <= 12) {

        if(b == 0 || b > 12) cout << "MMYY" << endl;
        else cout << "AMBIGUOUS" << endl;

    } else if(f > 12) {

        if(b == 0 || b > 12) cout << "NA" << endl;
        else cout << "YYMM" << endl;

    }

}