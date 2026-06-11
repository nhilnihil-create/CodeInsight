#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n, k;
    cin >> n >> k;
    k--;
    string s;
    cin >> s;
    rep(i,n){
        if(i == k){
            char a = tolower(s[i]);
            cout << a;
        }else{
            cout << s[i];
        }
    }
    cout << endl;
    
    return 0;
}