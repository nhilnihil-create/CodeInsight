#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll x, y;
    cin >> x >> y;

    vector<ll> vec;
    int ans = 0;
    ll num = x;
    while (num <= y){
        num *= 2;
        ans++;

    }
    
    cout << ans << endl;
    return 0;
}
