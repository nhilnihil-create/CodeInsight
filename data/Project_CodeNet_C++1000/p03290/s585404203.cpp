#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int D, G; cin >> D >> G;
    vector<int> prob(D), bonus(D);
    for (int i = 0; i < D; i++) {
        cin >> prob[i] >> bonus[i];
        bonus[i] = bonus[i] / 100;
    }
    G = G / 100;

    int tmp, cnt;
    int ans = inINF;
    int m;
    for (int i = 0; i < (1<<D); i++) {
        tmp = 0; cnt = 0;
        for (int j = 0; j < D; j++) {
            if(i & (1<<j)){
                tmp += prob[j] * (j+1);
                tmp += bonus[j];
                cnt += prob[j];
            }
            else{
                m = j; //立っていない最大のビットをmに入れる
            }
        }
        if(G <= tmp + (prob[m]-1) * (m+1)){
            if(G > tmp){
                cnt += (G - tmp - 1)/(m+1) + 1;
            }
            ans = min(ans, cnt);
        }
    }
    printf("%d\n", ans);


}
