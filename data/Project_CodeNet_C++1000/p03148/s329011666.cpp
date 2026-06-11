#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
typedef pair<ll,ll> pll;


ll n, k;
ll cnt[200005];
vector< pll > v;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        cin >> n >> k;
        for(ll i=0;i<n;i++) {
                ll x, y;
                cin >> x >> y;
                v.pb(make_pair(y, x));
        }
        sort(v.rbegin(), v.rend());
        ll ans = 0;
        priority_queue<pll, vector<pll>, greater<pll> > pq;
        ll c=0;
        ll sum=0;
        for(ll i=0;i<k;i++) {
                ll d = v[i].first;
                ll t = v[i].second;
                if(cnt[t] == 0) c++;
                cnt[t]++;
                ans += d; sum+=d;
        }
        ans += c*c;
        for(ll i=0;i<k;i++){
                ll d = v[i].first;
                ll t = v[i].second;
                if(cnt[t] > 1) pq.push(v[i]);
        }
        ll ret = ans;
        for(ll i=k;i<n;i++) {
                ll d = v[i].first;
                ll t = v[i].second;
                if(cnt[t] > 0) continue;
                if(pq.empty() == false){
                        pll yo = {-1,-1};
                        while(pq.empty()==false){
                                pll X = pq.top(); pq.pop();
                                if(cnt[X.second] > 1){
                                        yo=X; break;
                                }
                        }
                        if(yo == make_pair(-1LL,-1LL)) continue;
                        cnt[yo.second]--;
                        sum -= yo.first;
                        sum += d;
                        cnt[t]++;
                        c++;
                        pq.push(make_pair(d,t));
                        ret=max(ret, sum+c*c);
                }
        }
        cout << ret << endl;
        return 0;
}
