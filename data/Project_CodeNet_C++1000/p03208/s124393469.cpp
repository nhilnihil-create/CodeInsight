#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> h;
    for(int i=0;i<n;i++){
        ll e;
        cin >> e;
        h.push_back(e);
    }

    sort(h.begin(),h.end());

    ll ans=M;
    for(int i=k-1;i<n;i++) ans=min(ans,h.at(i)-h.at(i-(k-1)));

    cout << ans << endl;
}