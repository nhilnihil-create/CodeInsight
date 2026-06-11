#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

int main(void){
    ll n;
    cin >> n;
    vector<ll> a(110, 1);
    for(ll i = 2; i <= n; i++){
        ll count = 2;
        ll j = i;
        bool ok = true;
        while(ok==true){
            //cout << i << endl;
            //cout << j <<  " " << count << endl;
            if(j%count==0){
                j = j/count;
                a[count]++;
            }
            else if(j%count!=0)count++;
            if(j<count) ok = false;
        }
        //cout <<"aa" << endl;
    }
    ll ans = 0;
    //for(ll i = 0; i <= 20; i++)
      //  cout << i << " " << a[i] << endl;
    sort(a.begin(), a.end(), greater<ll>());
    if(a[0]>=75) ans=1;
    for(ll i = 0; i <= n; i++){
        if(a[i]<25) break;
        for(ll j = 0; j <= n; j++){
            if(a[j]<3) break;
            if(i!=j) ans++;
        }
    }
    for(ll i = 0; i <= n; i++){
        if(a[i]<15) break;
        for(ll j = 0; j <= n; j++){
            if(a[j]<5) break;
            if(i!=j){
                ans++;
            }
        }
        //cout << ans << endl;
    }
    for(ll i = 0; i <= n; i++){
        if(a[i]<5) break;
        for(ll j = i+1; j <= n; j++){
            if(a[j]<5) break;
            for(ll k = 0; k <= n; k++){
                if(a[k]<3) break;
                if(i!=j && j!=k && k!=i){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
