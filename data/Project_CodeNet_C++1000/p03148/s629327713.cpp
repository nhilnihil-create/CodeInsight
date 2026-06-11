#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,k,t,d;
    cin>>n>>k;
    vector<pair<ll,ll> > v;
    for(int i=0;i<n;i++){
    	cin>>t>>d;
    	v.pb(make_pair(d,t-1));
    }
    sort(be(v));
    reverse(be(v));
    set<ll> s;
    vector<ll> q;
    ll num=0;
    for(int i=0;i<k;i++){
    	if(s.count(v[i].second)){
    		q.pb(v[i].first);
    	}
    	s.insert(v[i].second);
    	num+=v[i].first;
    }
    t=s.size();
    vector<ll> makichan;
    for(int i=k;i<n;i++){
    	if(s.count(v[i].second)==0){
    		makichan.pb(v[i].first);
    	}
    	s.insert(v[i].second);
    }
    sort(be(q));
    reverse(be(q));
    sort(be(makichan));
    ll ans=t*t+num;
    while(!(q.empty()||makichan.empty())){
    	num-=q.back();q.pop_back();
    	num+=makichan.back();makichan.pop_back();
    	t++;
    	ans=max(ans,t*t+num);
    }
    cout << ans<<endl;
    return 0;
}