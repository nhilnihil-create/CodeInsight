#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

    string s;
    cin >> s; 

    ll cnt = 0;
    ll ans = 0;

    // 後ろから見る
    for(int i = s.size()-1; i >= 0; --i){
        if(i > 0 && s[i] == 'C' && s[i-1] == 'B'){
            // BCを連結して見る
            cnt++;
            i--;
        }
        else if(s[i] == 'A'){
            // BCの数だけAが転倒できる
            ans += cnt;
        } 
        else{
            // 途切れたらAは転倒する場所がなくなる
            cnt = 0;
        }
    }
    cout << ans << endl;

}
