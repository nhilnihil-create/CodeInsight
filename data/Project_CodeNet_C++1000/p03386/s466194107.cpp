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
#include <random>
#include <cassert>
#include <numeric>
#define ll long long int
#define LL unsigned long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;



int main() {
    ll a, b, k; cin >> a >> b >> k;
    vector<ll> ans;
    for(ll i = a;i < min(b,a + k); i++){
        ans.pb(i);
    }
    for(ll i = max(a,b-k+1); i <= b; i++){
        ans.pb(i);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    rep(i,ans.size()){
        cout << ans[i] << endl;
    }
}
