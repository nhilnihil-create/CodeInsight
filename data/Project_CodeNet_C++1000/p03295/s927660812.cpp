#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;
int n,m,ans = 0;

int main(){
    cin >> n >> m;
    pair<int, int> s[m];
    rep(i,m){
        cin >> s[i].second;
        cin >> s[i].first;
    }
    sort(s, s+m);
    int b = 0; //さいごに橋を取り除いた位置
    rep(i,m){
        if(s[i].second > b){ 
            b = s[i].first -1;
            ans += 1;
        }
    }
    cout << ans << endl;
}