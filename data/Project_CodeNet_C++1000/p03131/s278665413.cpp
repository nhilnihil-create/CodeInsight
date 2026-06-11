// https://atcoder.jp/contests/yahoo-procon2019-qual/tasks/yahoo_procon2019_qual_c

#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
using ll = long long;

ll k,a,b;
ll ans = 0;

void solve(){
    if(b-a<2){
        ans= k+1;
        }
    else{
        ans = max(0ll,(k-(a-1))/2)*(b-a) + a + (k-(a-1))%2;
    }
    cout << ans << endl;
}

int main(){
    cin >> k >> a >> b;
    solve();
}