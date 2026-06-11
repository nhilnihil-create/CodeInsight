#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(){
    ll n, m;
    cin >> n >> m;
    ll a[n];
    ll ans = 0;
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    ll sum[n];
    sum[0] = a[0]%m;
    for(ll i = 1; i < n; i++){
        sum[i] = (sum[i-1]+a[i])%m;
    }
    sort(sum, sum+n);
    ll count = 1;
    if(sum[0]==0) ans++;
    for(ll i = 1; i < n; i++){
        if(sum[i]==0) ans++;
        if(sum[i]==sum[i-1]) count++;
        else{
            //cout << count << endl;
            ans+=count*(count-1)/2;
            count=1;
        }
        if(i==n-1){
            ans+=count*(count-1)/2;
            //cout << i << " " << count*(count-1)/2 << endl;
        }
        //cout << i << " " << ans << " " << sum[i] << endl;
        //cout << sum[i] << endl;
    }
    cout << ans << endl;
    return 0;
}
