#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

map<ll, ll> prime;
void Factor(ll n){
    ll sq = sqrt(n) + 1;

    for(int i = 2; i <= sq; ++i){
        sq = sqrt(n) + 1;
        if(n%i == 0){
            if(prime.count(i) == 0)prime[i] = 0;
            while(n%i == 0){
                n /= i;
                prime[i]++;
            }
        }
    }

    if(n != 1){
        if(prime.count(n) == 0)prime[n] = 1;
        else prime[n]++;
    }
}

int main(){
    ll n;
    cin >> n;

    rep(i, n)Factor(i+1);

    ll over_3, over_5, over_15, over_25, over_75;
    over_3 = over_5 = over_15 = over_25 = over_75 = 0;
    
    all_map(itr, prime)if(itr->second >= 2){
        over_3++;
        if(itr->second >= 4)over_5++;
        if(itr->second >= 14)over_15++;
        if(itr->second >= 24)over_25++;
        if(itr->second >= 74)over_75++;
    }

    ll ans = over_75 + over_25 * (over_3-1) + over_15 * (over_5 -1) + (over_5 * (over_5-1)) / 2 * (over_3-2);
    
    cout << max((ll)0, ans) << endl;
}