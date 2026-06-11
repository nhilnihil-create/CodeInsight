#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
using Graph = vector<vector<int>>;

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end());
    ll ans = 0, drink = 0;
    for(int i=0;i<n;i++){
        if(drink + a[i].second <= m){
            ans += a[i].first * a[i].second;
            drink += a[i].second;
        }
        else{
            while(drink < m){
                ans += a[i].first;
                drink++;
            }
        }
    }

    cout<<ans<<endl;
}