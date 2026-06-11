#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    map<char,ll> mp;
    rep(i,N){
        string name;
        cin >> name;
        mp[name[0]]++;
    }
    vector<ll> cnt(5);
    string S = "MARCH";
    rep(i,5) cnt[i] = mp[S[i]];
    ll ans = 0;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<4;j++){
            for(int k=j+1;k<5;k++){
                ans += cnt[i]*cnt[j]*cnt[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}