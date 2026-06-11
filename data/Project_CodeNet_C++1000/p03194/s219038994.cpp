#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    long N, P;
    cin >> N >> P;

    // 割る数の初期値
    long  a = 2, count = 0, ans = 1;
    // √P ≧ a ( n ≧ a * a ) の間ループ処理
    while (P >= a * a) {
        // a で割り切れたら、a は素因数
        // そして、割られる数を a で割る
        // a で割り切れなかったら、 a を 1 増加させる
        if (P % a == 0) {
            count++;
            P /= a;
            if(count%N == 0){
                //cout << "OK" << endl;
                ans *= a;
            }
        } else {
            a++;
            //cout << a << endl;
            count = 0;
        }
    }
    if(N == 1) ans *= P;
    else if(count == N-1) ans *= P;

    cout << ans << endl;
}