#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;

//コンビネーションを10^9+7で割った余りを求める
const int MAX = 1000000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    int n;
    cin>>n;
    COMinit();
    string s;
    cin>>s;
    vector<int> alp(26);
    map<int,int> p;
    rep(i,n){
        alp[s[i]-'a']++;
    }
    int exist=0;
    rep(i,26){
        if(alp[i]>=1){
            exist++;
        }
        //cout<<alp[i]<<" ";
        p[alp[i]]++;
    }
    //cout<<endl;
    int64_t ans=1;
    rep(i,26){
        ans *= (alp[i]+1);
        ans %=MOD;
    }
    cout<<(ans%MOD)-1<<endl;
}