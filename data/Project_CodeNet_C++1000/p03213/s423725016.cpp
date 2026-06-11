#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
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
map<ll,int> mli; 
ll dfs(map<ll,int>::iterator itr, int mul){
    if(itr == mli.end()){
        if(mul == 1) return 1;
        else return 0;
    }
    ll res = 0;
    for(int i = 0;i < itr -> second +1; i++){
        if(mul % (i + 1) == 0){
            res += dfs(++itr, mul/(i + 1));
            itr--;
        }
    }
    return res;
}
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    rep(i,n){
        for(auto u : prime_factorize(i+1)){
            mli[u.first] += u.second;
        }
    }
    cout << dfs(mli.begin(), 75) << endl;
    return 0;
}