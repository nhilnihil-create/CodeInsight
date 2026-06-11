#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h,w;
    cin >> h >> w;
    vector<vector<char>> s(h+2,vector<char> (w+2,'0'));

    for(int i = 1;i < h+1;++i){
        for(int j = 1;j < w+1;++j){
            cin >> s[i][j];
        }
    }
    bool ok = true;
    rep(i,h+1){
        rep(j,w+1){
            if(s[i][j] == '#'){
                if(s[i-1][j] != '#' && s[i][j-1] != '#' && s[i][j+1] != '#' && s[i+1][j] != '#'){
                    ok = false;
                }
            }
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    cout << endl;
    return 0;
}
