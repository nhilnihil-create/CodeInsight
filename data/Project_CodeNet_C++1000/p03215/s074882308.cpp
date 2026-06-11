#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
//#define MOD 1000000007
#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int N,K; cin >> N >> K;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    vector<ll> sum(N+1);
    rep(i,N) sum[i+1] = sum[i]+a[i];
    vector<ll> b;
    rep(i,N)repr(j,i+1,N+1){
        b.push_back(sum[j]-sum[i]);
    }
    ll ans = 0;
    for(int i = 40; i >= 0; i--){
        int cnt = 0;
        rep(j,N*(N+1)/2){
            if((ans&b[j]) == ans && (1LL<<i)&b[j]) cnt++;
        }
        if(cnt >= K){
            ans += 1LL<<i;
        }
    }
    cout << ans << endl;

}

    

