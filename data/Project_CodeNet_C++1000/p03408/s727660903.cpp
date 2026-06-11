#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
    map<string, int> cards;
    
    int n; cin>>n;
    string s;
    rep(i,n){
        cin>>s;
        cards[s]++;
    }
    int m; cin>>m;
    rep(i,m){
        cin>>s;
        cards[s]--;
    }
    int ans = 0;
    
    for(auto c: cards){
        ans = max(c.second, ans);
    }
    
    cout << ans << endl;
    return 0;
}