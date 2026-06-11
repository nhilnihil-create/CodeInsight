#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Mat = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5+10;

int main(){
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int m;
    cin >> m;
    vector<string> t(m);
    rep(i,m) cin >> t[i];

    set<string> str;
    rep(i,n) str.insert(s[i]);

    int ans = 0;
    int sum = 0;
    for(auto x : str){
        sum = 0;
        rep(i,n){
            if(x==s[i]) ++sum;
        }
        rep(j,m){
            if(x==t[j]) --sum;
        }
        if(sum>ans) ans = sum;
    }
    cout(ans);


    return 0;
}