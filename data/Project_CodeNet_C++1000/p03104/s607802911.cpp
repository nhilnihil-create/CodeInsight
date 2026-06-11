#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(ll a){
    ll ans = 0;

    //i桁目について
    //入力に対してオーバーな分は0になるので気にしない
    for(int i=0;i<50;i++){
        //周期
        ll lp = (1LL<<(i+1));
        
        //既に迎えた周期*その半分が1の個数
        //0の帳尻合わせでaに1加算
        ll cnt = (a+1)/lp * (lp/2);

        //現在いる周期分の加算
        //0...0部分にいる時は0個
        ll d = (a+1)%lp - lp/2;
        if(d>0) cnt += d;

        //答えの作成は直接2のi乗を加算してやる
        if(cnt%2==1) ans += 1LL << i;
    }
    return ans;
}

int main(void){
    ll a,b;
    cin >> a >> b;

    //例えば4-8範囲C求めるときに、A:0-3,B:0-8としておくと
    //A xor C = B <=> A xor B = C
    //と変形できる。Aの逆元がA自身なのがポイント。
    ll ans = func(b) ^ func(a-1);
    cout << ans << endl;
    return 0;
}