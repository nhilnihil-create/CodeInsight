#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<string> s(N);
    rep(i, N) cin >> s[i];
    int ans = 0;

    //文字列の先頭が'B'で、末尾が'A'の文字列の個数
    int cnt_AB = 0;
    //文字列の末尾が'A'の文字列の個数
    int cnt_A = 0;
    //文字列の先頭が'B'の文字列の個数
    int cnt_B = 0;

    //いろいろな数え上げを行う
    rep(i, N){
        //各文字列内に含まれる'AB'の個数を数える
        string t = s[i];
        int len = (int)t.size();
        rep(j, len-1){
            if(t[j] == 'A' && t[j+1] == 'B') ans++;
        }

        //文字列の末尾、先頭に注目する
        if(t[0] == 'B' && t[len-1] == 'A') cnt_AB++;
        else if(t[0] == 'B') cnt_B++;
        else if(t[len-1] == 'A') cnt_A++;
    }

    if(cnt_A != 0 || cnt_B != 0){
        ans += min(cnt_A + cnt_AB, cnt_B + cnt_AB);
    }else{
        if(cnt_AB > 1) ans += (cnt_AB-1);
    }
    cout << ans << endl;
    return 0;
}