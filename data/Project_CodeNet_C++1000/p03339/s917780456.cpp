#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<P> sum(n+1);
    rep(i,n){
        if(s[i] == 'E') sum[i+1].first++;
        else sum[i+1].second++;
        sum[i+1].first += sum[i].first;
        sum[i+1].second += sum[i].second;
    }
    int ans = 1e9;
    rep(i,n){
        int cnt = 0;
        cnt += sum[i].second;
        cnt += sum[n].first - sum[i+1].first;
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}