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


    string s, t; cin >> s >> t;

    int n = s.size();
    int m = t.size();

    int idx = -1;
    for(int i = 0; i < n-m+1; ++i){ //move initial s pos
        bool flg = true;
        for(int j = 0; j < m; ++j){
            if(s[i+j]!='?' && s[i+j] != t[j]) flg = false;
        }

        if(flg) idx = i;    //preserve the latest starting pos
    }

    if(idx == -1) cout << "UNRESTORABLE" << endl;
    else{
        for(int i = idx; i < idx+m; i ++){
            s[i] = t[i-idx];
        }
        rep(i,n){
            if(s[i] == '?') cout << 'a';
            else cout << s[i];
        }
    }
    return 0;
}
