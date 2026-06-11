#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ce = 0;
    int cw = 0;
    rep(i,n){
        if(s[i] == 'E')ce++;
        else cw++;
    }
    int ans = 1e9;
    int e = ce;
    int w = 0;
    rep(i,n){
        if(s[i] == 'E') e--;
        ans = min(ans,e+w);
        if(s[i] == 'W') w++;
    }
    cout << ans << endl;
}