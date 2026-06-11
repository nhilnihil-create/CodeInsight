#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int n;
    cin >> n;

    vector<vi> open(n,vi(10));
    rep(i,n) rep(j,10) cin >> open[i][j];

    vector<vi> profit(n,vi(11));
    rep(i,n) rep(j,11) cin >> profit[i][j];

    ll ans=-1e9;
    for(int i=1;i<(1<<10);i++){
        ll prof=0;
        //shop j
        for(int j=0;j<n;j++){
            int cnt=0;
            //day k
            for(int k=0;k<10;k++){
                if(i>>k&open[j][k]){
                    cnt++;
                }
            }
            prof+=profit[j][cnt];
        }
        ans=max(ans,prof);
    }
    cout << ans << endl;
}