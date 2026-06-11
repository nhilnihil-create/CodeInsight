#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<ll> v(1000000);
    vector<ll> dp(1000000);
    dp[0] = 1;
    ll mod = 1e9+7;
    rep(i,n){
        cin >> v[i+1];
    }
    vector<ll> tmp;
    tmp.push_back(v[0]);
    for(int i = 1; i <=n;i++){
        if(tmp.back()!=v[i]){
            tmp.push_back(v[i]);
        }
    }
    vector<ll> s(1000000);
    for(int i = 1;i<tmp.size();i++){
        s[tmp[i]]+=dp[i-1];
        s[tmp[i]]%=mod;
        dp[i]=s[tmp[i]];
    }
    cout << dp[tmp.size()-1] << endl;
    return 0;
}