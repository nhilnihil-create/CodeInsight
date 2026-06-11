#include<bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(ll i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<P> a(n);
    vector<int> b;
    rep(i, n)cin >> a[i].first;
    rep(i, n)cin >> a[i].second;
    ll num1 = 0, num2 = 0, ans = 0;
    rep(i, n){
        if(a[i].first > a[i].second)b.push_back(a[i].first-a[i].second);
        else if(a[i].second > a[i].first){
            num1 += a[i].second-a[i].first;
            ans++;
        }
    }
    sort(rall(b));
    rep(i, b.size()){
        if(num1 > num2){
            ans++;
            num2 += b.at(i);
        }
    }
    if(num1 <= num2)cout << ans << endl;
    else cout << -1 << endl;
}
