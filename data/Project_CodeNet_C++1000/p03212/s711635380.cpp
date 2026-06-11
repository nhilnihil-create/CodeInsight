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
const ll MOD = 1e9 + 7;

int dfs(const string& s, int n) {
    ll sn = s == "" ? 0 : stol(s); 
    if (sn > n) return 0;
    int ret = 0;
    if (s.find('3') != string::npos 
     && s.find('5') != string::npos
     && s.find('7') != string::npos ) ret += 1; 
    ret += dfs(s + '3', n);
    ret += dfs(s + '5', n);
    ret += dfs(s + '7', n);
    return ret;
}

int main() {
    int n;
    cin >> n;
    cout << dfs("", n) << endl;
    return 0;
}