#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    string s[n];
    rep(i, n) cin >> s[i];
    string t[n];
    rep(i, n){
        bool flag = true;
        rep(j, n){
            if (i + j < n) t[j] = s[i + j];
            else t[j] = s[i + j - n];
        }
        rep(y, n){
            rep(x, n){
                if (t[x][y] != t[y][x]) flag = false;
            }
        }
        if (flag) ans ++;
    }
    cout << ans * n << endl;
    return 0;
}