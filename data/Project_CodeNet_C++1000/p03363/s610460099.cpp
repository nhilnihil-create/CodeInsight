#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
const int MAX = 510000;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    ll s = 0;
    map<ll,ll> mp;
    mp[0] = 1;
    rep(i,N) {
        cin >> A[i];
        s += A[i];
        mp[s]++;
    }
    ll ans = 0;
    for(auto itr = mp.begin();itr!=mp.end();itr++){
        //cout << itr->first << ":" << itr->second << endl;
        if(itr->second>1){
            ans += itr->second*(itr->second-1)/2;
        }
    }
    cout << ans << endl;
    return 0;
}