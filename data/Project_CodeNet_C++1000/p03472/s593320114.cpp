#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const int lim = 1000000007;

int main(){
    int N, H;
    cin >> N >> H;
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    //aの中で最大のダメージを格納
    int mx_a = 0;
    rep(i, N) mx_a = max(mx_a, a[i]);

    //bの中でmx_aよりも大きなダメージを与えられるものの数と、その合計を格納
    int cnt = 0;
    ll sum = 0;
    sort(b.begin(), b.end(), greater<int>());
    rep(i, N){
        if(b[i] > mx_a){
            cnt++;
            sum += b[i];
        }
        if(sum >= H){
            cout << cnt << endl;
            return 0;
        }
    }

    //刀を振ることで与えなければならないダメージを計算
    int d = H - sum;
    //d以上となるための、mx_aのダメージが与えられる刀を振る回数を求める
    int c = (d + mx_a -1) / mx_a;
    int ans = c + cnt;
    cout << ans << endl;
    return 0;
}