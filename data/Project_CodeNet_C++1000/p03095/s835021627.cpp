#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rp(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//出力するよ
void output_tate(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output_yoko(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}
int MOD = pow(10, 9) + 7;


const long long MAX=100000+1;
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

int kaijou(int n){
    if(n==0) return 1;
    else{
        return ((n%MOD)*(kaijou(n-1)%MOD))%MOD;
    }
}

signed main() {
    int n; string s;
    cin>>n>>s;
    
    //各文字の出現回数と各文字がダブっている組の数
    map<char,int> chars;
    map<char,int> kaburi;
    int kabu=0;
    COMinit();

    
    for(int i=0;i<n;i++){
        kaburi[s[i]]+=chars[s[i]];
        chars[s[i]]++;
    }

    int ans=1;

    for(auto c:chars){
        //cout<<c.second<<endl;
        ans=(ans%MOD*((c.second+1)%MOD))%MOD;
    }


    ans--;
    if(ans<0) ans+=MOD;
    

    cout<<ans%MOD<<endl;
}
