#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int N,K; cin >> N >> K;
    vector<Pi> dt(N);
    map<int,int> mp;
    priority_queue<int,vector<int>,greater<int>> q;
    set<int> s;
    rep(i,N){
        cin >> dt[i].second >> dt[i].first;
    }
    sort(dt.rbegin(),dt.rend());
    ll now = 0;
    ll ans = 0;
    rep(i,K){
        now += dt[i].first;
        s.insert(dt[i].second);
        mp[dt[i].second]++;
        if(mp[dt[i].second] >= 2) q.push(dt[i].first);
    }
    int m = s.size();
    ans = now+(ll)m*m;
    int cnt = 0;
    repr(i,K,N){
        if(mp[dt[i].second] == 0){
            if(!q.empty()){
                int u = q.top();
                q.pop();
                now -= u;
                now += dt[i].first;
                cnt++;
                mp[dt[i].second]++;
                ans = max(ans,now+(ll)(m+cnt)*(m+cnt));
            }
        }
    }
    cout << ans << endl;

}