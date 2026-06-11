#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")



int main() {
    string s; cin >> s;
    ll ans = 0;
    ll count = 0;
    ll pos = 0;

    for(int i = s.length()-1; i >= 1; i --){
        if(s[i-1] == 'B' && s[i] == 'C'){
            s[i-1] = 'D';
            s.erase(s.begin()+i);
        }
    }

    rep(i,s.length()){
        if(s[i] == 'A') count ++;
        else if(s[i] == 'D'){
            ans += count;
        }else{
            count = 0;
        }
    }

    cout << ans;


}