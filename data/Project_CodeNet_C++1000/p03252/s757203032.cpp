#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")




int main() {


    string s,t; cin >> s >> t;
    ll n = s.length();
    map<char,char> mpS,mpT;
    rep(i,26){
        mpS[(char)('a'+i)] = '.';
        mpT[(char)('a'+i)] = '.';
    }
    rep(i,n){
        if(mpS[s[i]] != '.' && mpS[s[i]] != t[i]){
            cout << "No";
            return 0;
        }
        if(mpT[t[i]] != '.' && mpT[t[i]] != s[i]){
            cout << "No";
            return 0;
        }
        if(mpS[s[i]] == '.') mpS[s[i]] = t[i];
        if(mpT[t[i]] == '.') mpT[t[i]] = s[i];

    }


    cout << "Yes";
    return 0;
}
