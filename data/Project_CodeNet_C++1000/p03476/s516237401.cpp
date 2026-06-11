#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;

bool is_prime(int N) {
    if (N == 1) return false;
    for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
    int q; cin >> q;
    V<P<int, int> > p(q);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        p[i] = make_pair(l, r);
    }

    V<int> memo(100010, 0);
    memo[0] = 0;
    memo[1] = 1;
    for(int i = 3; i < 100000; i+=2){
        if(is_prime(i) && is_prime((i + 1) / 2)){
            memo[i] = memo[i - 2] + 1;
        }else{
            memo[i] = memo[i - 2];
        }
    }

    for(int i = 0; i < q; i++){
        if(1 < p[i].first && 1 < p[i].second){
            cout << memo[p[i].second] - memo[p[i].first - 2] << endl;
        }else{
            cout << memo[p[i].second] - 1 << endl;
        }
    }

}
