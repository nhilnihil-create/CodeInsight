#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
const int MAX = 300;

vector<vector<char>> s(MAX,vector<char>(MAX));
int n;

bool same(int a, int b){
    bool f = true;
    rep(i,n){
        rep(j,n){
            if(s[(i+a)%n][(j+b)%n] != s[(j+a)%n][(i+b)%n]) f = false;
        }
    }
    return f;
}

int main(){
    cin >> n;
    rep(i,n){
        rep(j,n) cin >> s[i][j];
    }
    int ans = 0;
    if(same(0,0)) ans += n;
    for(int i = 1; i <= n-1; i++){
        if(same(i,0)) ans += n-i;
        if(same(0,i)) ans += n-i;
    }
    cout << ans << endl;
    return 0;
}