#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int D,G;
    cin >> D >> G;
    vector<int> p;
    vector<ll> c;
    rep(i,D){
        int t1,t2;
        cin >> t1 >> t2;
        p.push_back(t1);
        c.push_back(t2);
    }
    ll res = 1 << 29;
    for(int bit=0;bit < (1<<D); ++bit){
        ll sum = 0;
        ll num = 0;
        // 全完する問題を決め打ち
        rep(i,D){
            if(bit & (1<<i)){
                sum += c[i] + p[i] * 100 * (i+1);
                num += p[i];
            }
        }
        // 点数がGより上回っている
        if(sum >= G) res = min(res,num);
        //点数が高い順にみていく
        else{
            for(int i=D-1; i >= 0; --i){
                // 既に決め打ちされていた場合
                if(bit & (1 << i)) continue;
                for(int j=0;j < p[i]; ++j){
                    if(sum >= G) break;
                    sum += 100 * (i+1);
                    num++;
                }
            }
            res = min(res,num);
        }
    }
    cout << res << endl;
    return 0;
}