#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
typedef vector<int> vint;
typedef vector<long long> vlint;
typedef vector<string> vstr;
typedef vector<char> vchar;
typedef vector<vector<long long>> vlint2;

lint powint(lint x, lint y){
    int ret = 1;
    for (int i=0; i < y; i++) ret *= x;
    return ret;
};

lint mod = 1000000007;
vector<int> dx = {1, 0, 0, -1, 1, 1, -1, -1};
vector<int> dy = {0, -1, 1, 0, 1, -1, 1, -1};

map<char, long long> counter(string s){
    map<char, long long> count;
    rep(i, s.size()){
        count[s[i]] ++;
    }
    return count;
};

int powmod(int x, int y, int m){
    if (y == 0) return 1;
    return ((powint(powmod(x, y>>1, m), 2) % m) * powint(x, (y & 1))) % m;
};

int main() {
    string s; cin >> s;
    lint n = s.size();

    lint ans = 0;
    // aの連続をカウント
    lint a = 0;
    lint i = 0;
    while (i < n-2){
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
            ans += a + 1;
            s[i+2] = 'A';
            i++;
        }
        else if (s[i] == 'A'){
            a ++;
        }
        else{
            a = 0;
        }
        i++;
    }
    cout << ans << endl;

}

