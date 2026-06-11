#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;

string trs(string& s) {
    vector<int> cs(27, -1);
    int cnt = -1;
    string ret = "";
    for(char c : s) {
        int ic = c - 'a';
        if (cs[ic] == -1) {
            cs[ic] = ++cnt;
        }  
        ret += cs[ic] + 'a';
    }
    return ret;
}

int main() {
    string s, t;
    cin >> s >> t;
    string ret = trs(s) == trs(t) ? "Yes" : "No";
    cout << ret << endl;
    return 0;
}