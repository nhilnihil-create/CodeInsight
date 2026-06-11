#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll> p,c;
ll D,G;
const ll INF = ll(1e18)+5;
ll ans;
vector<bool> used;

void dfs(int t){
    if(t == D){
        // for(int i=0;i<D;i++){
        //     cerr <<"i="<<i <<"used=" << used[i] << endl;
        // }
        // score計算 Gを満たせたらansの値と比較して....
        ll sum =0;
        ll temp =0;
        for(int i=0;i<D;i++){
            if(used[i]){
                sum += ((i+1)*p[i] * 100 + c[i]);
                temp += p[i];
            }
            
        }
        // cerr <<"sum=" << sum <<"temp=" << temp << endl;
        if(sum>=G){
            ans = min(ans,temp);
            return;
        }
        for(int i=D-1;i>=0;--i){
            if(used[i]){
                continue;
            }
            for(int j=0;j<p[i]-1;j++){
                sum += (i+1)*100;
                temp++;
                if(sum>=G){
                    // cerr <<"temp=" << temp << endl;
                    ans = min(ans,temp);
                    return;
                }
            }
        }
        return;
    }
    
    dfs(t+1);
    used[t] = true;
    dfs(t+1);
    used[t] = false;
}

int main() {
    ans = INF;
    cin >> D >>G;
    used.resize(D,false);
    for(int i=0;i<D;i++){
        ll a,b;
        cin >> a >>b;
        p.push_back(a);
        c.push_back(b);
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}