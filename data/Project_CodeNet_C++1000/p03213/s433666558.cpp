#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
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

int main(){
    int N;
    cin >> N;
    map<int, int> M;
    rep(i,N) {
        auto F = prime_factorize(i+1);
        for (int j=0; j<F.size(); j++) {
            M[F[j].first] += F[j].second;
        }
    }
    
    int ans = 0;
    int num[5] = {75,25,15,5,3};
    int s[5] = {};
    for (auto m:M) {
        rep(i,5) {
            if (m.second+1>=num[i]) s[i]++;
        }
    }
    
    ans += s[0];
    ans += s[1]*(s[4]-1);
    ans += s[2]*(s[3]-1);
    ans += s[3]*(s[3]-1)/2*(s[4]-2);

    cout << ans << endl;


}
