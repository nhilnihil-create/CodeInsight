#include <iostream>
#include <iomanip>
#include <map>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    repi(i,n,0){
        int k;
        cin >> k;
        repi(j,k,0){
            int a;
            cin >> a;
            mp[a]++;
        }
    }
    int ans = 0;
    for(auto itr = mp.begin();itr != mp.end();itr++){
        if(itr->second == n)ans++;
    }
    cout << ans << endl;
    return 0;
}