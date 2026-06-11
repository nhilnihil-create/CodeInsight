
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    //左側からスタートし、続いている区間の数をactiveで記録する
    int ans=0;
    int active=0;
    rep(i,n){
        //もしactiveが足りていたらactiveをh[i]に合わせる
        //新たに区間を始める必要はない
        if(active >= h[i]){
            active = h[i];
        }
        //activeが足りていなかったらそこから足りない分の区間を始める
        else{
            ans += h[i]-active;
            active=h[i];
        }
    }
    cout << ans << endl;

}