#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

vector<long long> divisor(long long n) {
vector<long long> ret;
for (long long i = 1; i * i <= n; i++) {
if (n % i == 0) {
ret.push_back(i);
if (i * i != n) ret.push_back(n / i);
}
}
sort(ret.begin(), ret.end()); // 昇順に並べる
return ret;
}


int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vl A=divisor(M);
    reverse(A.begin(), A.end());
    for(auto p: A){
        if(M/p>=N){
            print(p)return 0;
        }
    }

    return 0;
}