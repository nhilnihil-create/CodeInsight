#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
#define ng 100010
typedef pair<ll,ll> pair;

int main(){
    ll n;
    cin >> n;
    ll m = n / 2;
    ll even[ng];
    ll odd[ng];
    ll max1,max2;
    max1 = 0;max2 = 0;
    ll maxeven,maxodd;
    for(ll i = 0; i < ng; i++){
        even[i] = 0;
        odd[i] = 0;
    }
    for(ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        if(i % 2 == 0){
            even[temp]++;
            if(max1 < even[temp]){
                max1 = even[temp];
                maxeven = temp;
            }
        }
        else{
             odd[temp]++;
             if(max2 < odd[temp]){
                max2 = odd[temp];
                maxodd = temp;
            }
        }
    }
    sort(even,even+ng,greater<>());
    sort(odd,odd+ng,greater<>());
    ll ans = 0;
    /*for(ll i = 1; i < ng;i++){
        ans += even[i];
        ans += odd[i];
    }*/
    if(maxeven != maxodd){
        ans = n - max1 - max2;
    }
    else{
        ans = n-max(max1+odd[1],max2+even[1]);
    }

    cout << ans << endl;
}