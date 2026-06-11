#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for(int i = k; i < (n); i++)
using ll = long long;

int main(){
    string s;
    cin >> s;
    string m, y;
    rep(i, 0, 2){
        m += s[i];
        y += s[i+2];
    }
    bool my_format = 0, ym_format = 0;
    int mm = stoi(m);
    int yy = stoi(y);
    if (1 <= mm && mm <=12) my_format = 1;
    if (1 <= yy && yy <=12) ym_format = 1;

    string judge;
    if (my_format && ym_format) judge = "AMBIGUOUS";
    else if (my_format) judge = "MMYY";
    else if (ym_format) judge = "YYMM";
    else judge = "NA";
    cout << judge << endl;
    return 0;
}   