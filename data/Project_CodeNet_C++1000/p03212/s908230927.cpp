#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

vector<ll> v;
ll n;

bool check(ll x) {
    string s = to_string(x);
    bool three = false, five = false, seven = false;
    rep(i,s.size()) {
        if(s[i] == '3') {
            three = true;
        }
        if(s[i] == '5') {
            five = true;
        }
        if(s[i] == '7') {
            seven = true;
        }
    }
    if(three == 1 && five == 1 && seven == 1) {
        return true;
    } else {
        return false;
    }
}

void dfs(string s) {
    ll x = stoll(s);
    if(x > n) {
        return;
    } 
    v.push_back(x);
    dfs(s + "3");
    dfs(s + "5");
    dfs(s + "7");
}

int main() {
    scanf("%lld",&n);
    dfs("3");
    dfs("5");
    dfs("7");
    int ans = 0;
    rep(i,v.size()) {
        if(check(v[i])) {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}