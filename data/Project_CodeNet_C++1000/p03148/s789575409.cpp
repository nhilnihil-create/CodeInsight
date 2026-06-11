#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    ll n,k;
    cin >> n >> k;
    priority_queue<pll> pq;
    rep(i,n){
        ll t,d;
        cin >> t >> d;
        --t;
        pq.push(pll(d,t));
    }

    priority_queue<pll,vector<pll>,greater<pll>> used;
    vector<int> cnt(n,0);
    ll c = 0;
    ll res = 0;
    rep(i,k){
        res += pq.top().first;
        if(cnt[pq.top().second] == 0) ++c;
        cnt[pq.top().second] ++;
        used.push(pq.top());
        pq.pop();
    }

    ll ans = res + c * c;

    while(!pq.empty() && !used.empty()){
        bool ok = true;
        while(cnt[pq.top().second]>0){
            pq.pop();
            if(pq.empty()){
                ok = false;
                break;
            }
        }
        while(cnt[used.top().second]==1){
            used.pop();
            if(used.empty()){
                ok = false;
                break;
            }
        }

        if(!ok) break;

        res -= used.top().first;
        cnt[used.top().second] --;
        used.pop();

        res += pq.top().first;
        cnt[pq.top().second] ++;
        pq.pop();

        c++;
        ans = max(ans,res + c * c);
    }

    cout << ans << endl;
    return 0;
}