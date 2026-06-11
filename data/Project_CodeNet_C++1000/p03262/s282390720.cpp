#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

//ユークリッドの互除法
ll gcd(ll x,ll y){
    if(x > y) swap(x,y);
    if(x == 0) return y;
    return gcd(x,y%x);
};

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = abs(a[i]-x);
    }
    int ans = a[0];
    for(int i = 0; i < n; i++){
        ans = gcd(ans,a[i]);
    }
    cout << ans << endl;
    return 0;
}