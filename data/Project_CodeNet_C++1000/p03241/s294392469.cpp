#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);
//----------------------------------------------------------------

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

ll tmp = 1;
ll sum = 1;
ll ans = 1;
ll N,M;

void dfs(vector<pair<long long, long long> > &F,int i) {
    if (F.size()==i) {
        //cout << tmp << " " << sum << endl;
        if (sum>=N) ans = max(ans,tmp);
    }
    else {
        rep(j,F[i].second+1) {
            ll t = pow(F[i].first,F[i].second-j);
            ll s = pow(F[i].first,j);
            tmp *= t;
            sum *= s;
            dfs(F,i+1);
            tmp /= t;
            sum /= s;
        }
    }
}

int main(){
    cin >> N >> M;

    auto F = prime_factorize(M);
    dfs(F,0);
    cout << ans << endl;
}
