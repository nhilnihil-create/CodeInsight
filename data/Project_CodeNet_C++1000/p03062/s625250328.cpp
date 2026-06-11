#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int MX = 1000000001;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i] < 0) cnt++; 
    }
    ll total  = 0;
    rep(i,n) total += abs(a[i]);
    if(cnt%2 == 1){
        int mn = MX;
        rep(i,n) mn = min(mn,abs(a[i]));
        // cout << abs(a[5]) << endl;
        // cout << mn << endl;
        total -= 2*mn;
    }

    cout << total << endl;
}
