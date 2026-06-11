#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<pair<ll, ll>> res;
    ll sum;
    if(N % 2 == 1) sum = N-1;
    else sum = N;
    rep(i, 1, N+1){
        rep(j, 1, N+1){
            if(j <= i || j == sum - i + 1) continue;
            res.push_back({i, j});
        }
    }
    cout << res.size() << endl;
    for(auto p : res){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}