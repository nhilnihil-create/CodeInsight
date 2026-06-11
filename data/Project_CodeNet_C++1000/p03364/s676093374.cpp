#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define fs first
#define sc second

int main(void){
    int n;
    cin >> n;
    vector<vector<int>> be(n,vector<int>(n,0));
    vector<vector<int>> af(n,vector<int>(n,0));
    rep(i,n){
        string tmp;
        cin >> tmp;
        rep(j,n){
            be[i][j] = tmp[j]-'a';
        }
    }
    int ans = 0;
    int a=0;
    rep(b,n){
        rep(x,n){
            rep(y,n){
                af[(x+a)%n][(y+b)%n] = be[x][y];
            }
        }
        for(int x=1;x<n;x++){
            for(int y=0;y<x;y++){
                if(af[x][y] != af[y][x]){
                    goto wrong;
                }
            }
        }
        ans++;
        wrong:;
    }
    cout << ans*n << endl;
}

