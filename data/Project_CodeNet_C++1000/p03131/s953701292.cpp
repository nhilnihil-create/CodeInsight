#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;

const int D = 60;
const int max_n = 200005;

ll cal(ll a, ll b, ll k){
    ll n = (k-(a-1))/2;
    if(b-a-2ll>0){
        return (b-a-2ll) * n + k + 1ll;
    }else{
        return k + 1ll;
    }
}


int main() {
    ll k, a, b; cin >> k >> a >> b;
    ll ans = cal(a, b, k);
    cout << ans << endl;
}


