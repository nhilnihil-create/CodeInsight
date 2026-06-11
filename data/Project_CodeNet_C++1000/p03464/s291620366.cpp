#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    ll k;
    cin >> k;
    vector<ll> a(k);
    rep(i, k)cin >> a[i];

    ll low = 2, high = 2;
    reverse(ALL(a));

    rep(i, k){
        if((low/a[i])*a[i] < low)low=(low/a[i])*a[i]+a[i];
        high = (high/a[i])*a[i]+a[i]-1;
        if(high < a[i] || low > high){
            cout << -1;
            return 0;
        }
        // cout << a[i] << " in " << low << " & " << high << endl;
    }
    cout << low << " " << high << endl;
}