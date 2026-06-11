#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n,m;cin >>n >>m;
    vector<P> res;
    rep(i,n){
        int a,b;cin >> a >> b;
        res.emplace_back(a,b);
    }
    sort(res.begin(),res.end());
    int cnt = 0;
    int ans = 0;
    rep(i,n){
        auto hoge = res[i];
        int val = hoge.first,num = hoge.second;
        if(cnt + num >= m){
            ans += (m-cnt)*val;
            break;
        }
        cnt += num;
        ans += num*val;
    }
    cout << ans << endl;
    return 0;
}