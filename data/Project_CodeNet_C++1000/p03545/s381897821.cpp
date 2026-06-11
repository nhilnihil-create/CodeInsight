#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

int main() {

    int n = 3;
    int a[4];
    string s; cin >> s;
    rep(i,4) a[i]  = (int)(s[i]-'0');
    int cal = 0;
    char e[3];

    for(int bit = 0; bit < (1<<3); ++bit){
        cal = a[0];
        for(int i = 0; i < n; i ++){
            if(bit & (1 << i)){
                e[i] = '+';
                cal += a[i+1];
            }else{
                e[i] = '-';
                cal -= a[i+1];
            }
        }
        if(cal == 7){
            break;
        }
    }

    cout << a[0] << e[0] << a[1] << e[1] << a[2] << e[2] << a[3] << "=7";
    return 0;
}









