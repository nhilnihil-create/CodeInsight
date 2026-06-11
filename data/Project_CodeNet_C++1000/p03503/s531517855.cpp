#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n,vector<int>(10));//f
    vector<vector<int>> vec2(n,vector<int>(11));//p
    rep(i,n)rep(j,10) cin >> vec[i][j];
    rep(i,n)rep(j,11) cin >> vec2[i][j];
    ll ans=-10000000000;
    rep(i,1<<10){
        if(i==0) continue;
        bitset<10> bit(i);
        ll score=0;
        rep(i,n){
            int cnt=0;
            rep(j,10) if(bit.test(j)&&vec[i][j]==1)cnt++;
            score+=vec2[i][cnt];
        }
        ans=max(ans,score);
    }
    cout <<  ans << endl;
}
