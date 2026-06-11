#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const int lim = 1000000007;

int main(){
    string S;
    cin >> S;
    int N = (int)S.size();

    //xを除いたSの文字の並びかた
    string t;
    rep(i, N){
        if(S[i] == 'x') continue;
        t.push_back(S[i]);
    }

    //xを除いたSの逆順の文字の並び方
    string t_rev;
    reverse(S.begin(), S.end());
    rep(i, N){
        if(S[i] == 'x') continue;
        t_rev.push_back(S[i]);
    }

    //tとt_revが一致しないならば、回文にはできない
    if(t != t_rev){
        cout << -1 << endl;
        return 0;
    }

    //x以外の文字の個数の半分を求める
    int val = ((int)t.size() + 2 - 1) / 2;
    vector<int> cnt_a;
    vector<int> cnt_b;
    int cnt = 0;
    rep(i, N){
        if(S[i] == 'x') cnt++;
        else{
            cnt_a.push_back(cnt);
            cnt = 0;
        }
        if((int)cnt_a.size() == val) break;
    }
    reverse(S.begin(), S.end());
    cnt = 0;
    rep(i, N){
        if(S[i] == 'x') cnt++;
        else{
            cnt_b.push_back(cnt);
            cnt = 0;
        }
        if((int)cnt_b.size() == val) break;
    }
    int ans = 0;
    rep(i, (int)cnt_a.size()){
        ans += fabs(cnt_a[i] - cnt_b[i]);
    }
    cout << ans << endl;
    return 0;
}