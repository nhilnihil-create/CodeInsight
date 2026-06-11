#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

bool f(int x) {
    return x>0 && x<=12;
}

int main(){
    string s;
    cin >> s;
    int x = (s[0]-'0')*10 + s[1]-'0';
    int y = (s[2]-'0')*10 + s[3]-'0';
    //debug(x); debug(y);

    string ans;
    if (f(x) && f(y)) ans = "AMBIGUOUS";
    else if (!f(x) && !f(y)) ans = "NA";
    else if (f(x) && !f(y)) ans = "MMYY";
    else ans = "YYMM";
    
    cout << ans << endl;
    return 0;
}
