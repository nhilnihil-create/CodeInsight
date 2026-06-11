#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

string Long2Bin(ll n){
    if(n == 1)return "1";
    else if(n == 0)return "0";

    return Long2Bin(n/2)  + Long2Bin(n%2);
}

int main(){
    ll n;
    cin >> n;

    //プラスの部分だけ
    rep(bit, (1 << 16)){
        ll score = 0;
        rep(i, 16)if((1 << i) & bit){
            score += pow(2, 2*i);
        }

        //残りの数の符号を反転したもの
        ll score_mi = score - n;

        ll isok = true;
        rep(i, 32)if((1 << i) & score_mi){
            if(i&1)continue;

            //負の数の桁（奇数桁）でない値が必要ならダメ
            isok = false;
            break;
        }

        if(isok){
            cout << Long2Bin(score + score_mi) << endl;
            return 0;
        }
    }
}