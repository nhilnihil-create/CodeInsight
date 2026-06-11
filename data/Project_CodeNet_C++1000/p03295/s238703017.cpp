#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> vp(M);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        vp[i]=make_pair(b-1,a-1);
    }
    // bの小さい順にみていく
    sort(vp.begin(),vp.end());
    ll ans = 0;
    ll last_cut = 0;
    rep(i,M){
        if(i!=0){
            if(last_cut<=vp[i].second){
                // b-1とbの間で橋を落とす
                last_cut = vp[i].first;
                ans++;
            }
        }else{
            last_cut = vp[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}