#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int a[100000];
    int n;
    cin >> n;
    rep(i,n) cin >> a[i];
    map<int,int> mp;
    rep(i,n) mp[a[i]]++;
    int ans = 0;
    for(auto p: mp){
        int x = p.first;
        int y = p.second;
        if(y < x) ans += y;
        else ans += y - x;
    }
    cout << ans << endl;
}