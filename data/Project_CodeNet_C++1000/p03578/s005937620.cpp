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
    ll a[n];
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    ll m;
    cin >> m;
    ll t[m];
    for(ll i = 0; i < m; i++)
        cin >> t[i];
    sort(a, a+n); sort(t, t+m);
    bool ok = true;
    ll count = 0;
    for(ll i = 0; i < m; i++){
        //cout << t[i] << endl;
        for(ll j = count; j < n; j++){
            //cout << t[i] << " " << a[j] << endl;
            if(t[i]>a[j]) continue;
            else if(t[i]==a[j]){
                count = j+1;
                //cout <<"aaa" << endl;
                break;
            }
            else if(t[i]<a[j]){
                ok = false; break;
            }
        }
        if(ok==false) break;
    }
    if(ok==true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
