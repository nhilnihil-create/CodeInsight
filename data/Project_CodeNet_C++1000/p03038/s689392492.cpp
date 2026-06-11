#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N, M;
    cin >> N >> M;

    map<ll,ll> nums;
    REP(i, N){ 
       ll A;
       cin >> A;
       nums[A]++;
    }
    REP(i, M){
       ll B, C;
       cin >> B >> C;
       nums[C] += B;
    }

    ll count = 0;
    ll total = 0;
    for( auto it = nums.rbegin(); it != nums.rend(); it++ ){
       ll n = min( N-count, it->second );
        total += n *(it->first);
       count += n;

       if( count == N ) break;
    }

    cout << total << endl;
}
