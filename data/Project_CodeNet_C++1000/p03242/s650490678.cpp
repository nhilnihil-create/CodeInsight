#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P pair<int, int>
#define rep(i,n)         for(int i=0; i<(n); i++)
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"

//----------------------------------------------------

int main(){
    string s; cin >> s;
    rep(i, s.size()){
        if(s[i] == '1') s[i] = '9';
        else if(s[i] == '9') s[i] = '1';
    }
    cout << s << endl;
}