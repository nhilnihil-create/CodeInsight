#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << setw(10) << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

bool can_eternal(ll A, ll B, ll C, ll D){
    // 最初から在庫足りてない
    if(A<B){
        return false;
    }

    // 補充より消費が速い
    if(B>D){
        return false;
    }

    // 以降、A>=B, B<=D

    // AからBをギリギリまで引いた状態
    ll start = A % B;
    ll step = D-B;

    // 次の飲みで終わる
    if(start>C){
        return false;
    }

    if(step==0){
        if(start<=C){
            return true;
        }else{
            return false;
        }
    }

    // 危険ゾーンがない場合とは
    if(B-C<=1){
        return true;
    }

    if(step==1){
        return false;
    }

    ll left = C+1;
    ll right = B; // 含まない

    // 幅が広いので踏む
    if(right - left >= step){
        return false;
    }

    step = gcd(step, B);

    // 幅が広くなくても踏むときは踏む
    // leftの直前まで移動
    ll diff = left - start;
    ll n = diff / step;
    n -= 3; // ちょっと引く・・・
    if(n>0){
        start += step * n;
    }

    // 危険ゾーンの直前まで来た
    while(start < right){
        start += step;
        if(left <= start && start < right){
            return false;
        }
    }

    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll T;
    cin >> T;

    FOR(i, 0, T){
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        
        bool can = can_eternal(A, B, C, D);
        if(can){
            p_yes();
        }else{
            p_no();
        }
    }
    
    return 0;
}