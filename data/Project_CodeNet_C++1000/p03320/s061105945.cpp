#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = (int)(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = (int)(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = (1 << 30) - 1;
const long long LLINF = 1LL << 61;
const long long MOD = 1000000007LL;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

lint digit_sum(lint n){
    lint res = 0;
    while(n > 0LL){
        res += n % 10LL;
        n /= 10LL;
    }
    return res;
}

lint next_snuke(lint n){
    int cnt = 2;
    lint tmp = n;
    while(tmp > 0LL){
        tmp /= 10LL;
        ++cnt;
    }
    lint d = 10, res = n + 1LL;
    reps(i, cnt){
        lint now = d * ((n + d) / d + 1LL) - 1LL;
        if(now * digit_sum(res) < res * digit_sum(now)){
            res = now;
        }
        d *= 10LL;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;

    lint ans = 1;
    rep(i, k){
        cout << ans << endl;
        ans = next_snuke(ans);
    }

    return 0;
}