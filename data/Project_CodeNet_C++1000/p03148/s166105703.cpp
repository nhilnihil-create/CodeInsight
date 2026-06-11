#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N, K; cin >> N >> K;
    //F_set := 各ネタで一番基礎ポイントが高いもの
    //S_set := F_set以外
    vector<int> F_set, S_set;
    unordered_map<int,int> MP;

    //F_setとS_setに分類します。
    for(int i = 0 ; i < N; i++){
        int t, d;
        cin >> t >> d;
        //ps[i] = {t, d};
        if(MP[t] == 0) MP[t] = d;
        else{
            if(MP[t] < d){
                S_set.push_back(MP[t]);
                MP[t] = d;
            }else{
                S_set.push_back(d);
            }
        }
    }
    //(mapを全部表示するならunordered_mapの方が良い)
    for(auto e: MP){
        F_set.push_back(e.second);
    }
    sort(S_set.begin(), S_set.end(), greater<int>());
    sort(F_set.begin(), F_set.end(), greater<int>());

    //　各種類ポイントの時の最大値を求めて満足ポイント最大値をansとする
    ll ans = 0;
    ll pref = 0;    // 前のF_setの和を表示
    ll pres = 0;    // 前のS_setの和を表示
    // KとS_setの大小関係で場合分け
    if(K <= S_set.size()){
        for(int i = 0; i < K; i++){
            pres += S_set[i];
        }
        ans = pres;
        //iは種類数
        for(int i = 1; i <= K; i++){
            if(i - 1 >= F_set.size()) break;
            ll tmp = 0;
            tmp = (ll)i * (ll)i;
            pres -= S_set[K - i];
            pref += F_set[i-1];
            tmp += pres + pref;
            ans = max(ans, tmp);
        }
    }else{
        for(int i = 0; i < S_set.size(); i++){
            pres += S_set[i];
        }
        for(int i = 0; i < K - S_set.size(); i++){
            pref += F_set[i];
        }
        ans = pres + pref + pow((K - S_set.size()), 2);
        for(int i = K - S_set.size() + 1; i <= K; i++){
            if(i - 1 >= F_set.size()) break;
            ll tmp = 0;
            tmp = (ll)i * (ll)i;
            pres -= S_set[K - i];
            pref += F_set[i-1];
            tmp += pres + pref;
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}