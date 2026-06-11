#include<bits/stdc++.h>
using namespace std;
/*
alias p='g++ -std=c++17 -O2 pra.cpp'
alias pg='g++ -std=c++17 -O2 -g pra.cpp'
alias s='g++ -std=c++17 -O2 -g subpra.cpp'
alias ss='g++ -std=c++17 -O2 -g sspra.cpp'
ulimit -c unlimited
alias a='./a.out'
cd programming
cd cpp
cd practice

*/
using ll = long long;
#define rep(i, n) for(int i=0; i<(n); i++)
//if (i) cout << " "; で最初のみ空白文字を出力することができる
#define Sort(v) sort((v).begin(), (v).end())
#define pb push_back
using veci = vector<int>;
using vecs = vector<string>;
using vecd = vector<double>;
using vecl = vector<long long>;
using vecb = vector<bool>;
using G = vector<vector<int>>;
using P = pair<int, int>;
double PI = acos(-1);
ll lINF = LLONG_MAX; ll lmINF = LLONG_MIN;
int INF = INT_MAX; int mINF = INT_MIN;
//const ll mod = 1000000007;
int main() {
    cout.precision(10);
    cin.tie(0);//cin高速化
    int d, g; cin >> d >> g;
    g /= 100; 
    veci p(d), c(d);
    for(int i=0; i<d; i++){
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }
    vecb seen(d, false);//見たかどうかの配列は初期値falseが都合がよい
    int ans = 1e9;
    int cnt;
    int goal;
    for(int bit = 0; bit<(1 << d); ++bit){
        for(int i=0; i<d; i++) seen[i] = false;
        cnt = 0;
        goal = 0;
        for(int j=0; j<d; j++){//jは0オリジンでbitを探索する
            if (bit&(1<<j)){//これで選ばれれば全部解く
                goal += ((j+1)*p[j] + c[j]);
                cnt += p[j];
                seen[j] = true;
            }
        }
        if (goal < g){
            for(int i=d; i>=0; --i){
                if (!seen[i]){//まだ残っているなら
                    for(int j=p[i]; j>0; --j){
                    cnt++;
                    goal += i+1;
                    if (goal>=g) break;
                    if (j ==1) break;
                }
            }
            if (goal>=g) break;
        }
        }
        if (goal >= g) ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}