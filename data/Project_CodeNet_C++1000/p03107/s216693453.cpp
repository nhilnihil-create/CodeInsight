#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

const ll MOD = 1000000007LL;

int main(){
    string s;
    cin >> s;
    vector<char> c;
    int f = 0;
    ll ans = 0;

    rep(i, s.size()){
        
        if(i == 0) {
            c.push_back(s[i]);
            continue;
        }
        if(f < 0) {
            c.push_back(s[i]);
            f++;
            continue;
        }
        if(s[i] != c[f]){
            ans += 2;
            c.pop_back();
            f--;
        }else{
            c.push_back(s[i]);
            f++;
        }
    }
    cout << ans << endl;

    return 0;
}

/*
22222

 1011
11011010001011
*/
