#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#include<map>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main(){
    int N;  cin >> N;
    vector<ll> v(N);
    cin >> v[0];
    for(int i=1; i<N; i++){
        ll a;  cin >> a;
        v[i] = v[i-1] + a;
    }
    map<ll,ll> mp;
    for(int i=0; i<N; i++)  mp[v[i]]++;
    mp[0]++;
    ll ans = 0;
    for(auto i=mp.begin(); i!=mp.end(); i++){
        ll t = i->second;
        ans += t*(t-1)/2;
    }
    cout << ans << endl;
    return 0;
}