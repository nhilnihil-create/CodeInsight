#include <bits/stdc++.h>
using namespace std;

int main(){
     int n, m;
     cin >> n >> m;
     
     // 各頂点の位置を入力として受け取る
     vector<long long> x(m);
     for (int i = 0; i < m; i++) cin >> x[i];
     
     // コマの個数が配置場所の個数以上である場合は, 移動の必要性がない
     if (n >= m){
         cout << 0 << endl;
         return 0;
     }
     
     // 訪れられない開区間 の和を最大化するとよい
     // そのためにまずは現在のポジションを昇順にする
     sort(x.begin(),x.end());
     
     // 訪れられない開区間 の和を最大化するとよい
     // それぞれの点の間の距離を計算する
     // その後, 訪れなければならない区間の幅を小さい方から考える
     //　そのために, sortによって, 昇順に整列しておく
     vector<long long> diff(m-1);
     for (int i = 0; i < m-1; i++) diff[i] = x[i+1] - x[i];
     sort(diff.begin(),diff.end());
     
     // 大きい方からn個の区間は訪れなくて良い
     // m-n個の区間を小さい方から訪れる.
     long long ans = 0;
     for (int i = 0; i < m-n; i++) ans += diff[i];
     
     // 答えを出力しよう
    cout << ans << endl;
     return 0;
}

