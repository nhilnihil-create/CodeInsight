#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> pr(n);
    rep(i, 0, n){
        cin >> pr[i].first;
        pr[i].second = i+1;
    }
    sort(pr.begin(), pr.end());
    pr.push_back({-1,-1});
    ll ans = 0, tmp = 1;
    rep(i, 0, n) {
        if(pr[i].second < pr[i+1].second) {
            tmp++;
        }else{
            ans = max(ans, tmp);
            tmp = 1;
        }
    }
    cout << n - ans << endl;
    return 0;
}