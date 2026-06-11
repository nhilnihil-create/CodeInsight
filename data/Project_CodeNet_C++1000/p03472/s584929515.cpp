#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1001001001;
const ll mod = 1000000007;

int main(){
    int n, h; cin >> n >> h;
    vector<pair<ll, ll>> a(n);
    vector<ll> b(n);
    ll st = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        b[i] = a[i].second;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        if(b[i] > a[0].first){
            st += b[i];
            cnt++;
        }
    }
    if(st >= h){
        sort(b.begin(), b.end(), greater<ll>());
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            tmp += b[i];
            if(tmp >= h){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }
    else{
        h -= st;
        cout << cnt + (h + a[0].first - 1) / a[0].first << endl;
    }
    
}