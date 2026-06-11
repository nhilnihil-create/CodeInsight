#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const ll INF = pow(10, 9);

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    //絶対値の最小値を格納
    ll mn = INF;
    //最初に負の値の数を数える
    int minus = 0;
    //全体の絶対値の和
    ll sum = 0;

    //最小値と、負の数の数を数える、また、全体の絶対値の和を求める
    rep(i, N){
        if(mn > fabs(a[i])) mn = fabs(a[i]);
        if(a[i] < 0) minus++;
        sum += fabs(a[i]);
    }

    ll ans = sum;
    if(minus % 2 != 0) ans -= (mn*2);
    cout << ans << endl;
    return 0;
}