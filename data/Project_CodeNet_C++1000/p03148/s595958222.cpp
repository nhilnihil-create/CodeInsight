#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll t[n], d[n];
    multiset<pair<ll, int> > ms, tmp;
    set<ll> s, se;
    for(int i=0;i<n;i++){
    	cin >> t[i] >> d[i];
    	s.insert(t[i]);
    	ms.insert({d[i], i});
    }
    ll sum = 0;
    multiset<ll> a;
    for(auto itr = ms.end() ; itr != ms.begin();){
    	itr--;
    	if(se.count(t[itr->second]) || se.size() == k){
    		if(se.count(t[itr->second]) == 0) tmp.insert(*itr);
    		continue;
    	}
    	else{
    		se.insert(t[itr->second]);
    		tmp.insert(*itr);
    		a.insert(itr->first);
    		sum += itr->first;
    	}
    }
    for(auto& i: tmp) ms.erase(ms.find(i));
    ll maki = se.size();
    sum += maki * maki;
    ll idx = maki;
    tmp.clear();
    for(auto itr = ms.end();itr != ms.begin() && idx < k;idx++){
    	itr--;
    	sum += itr->first;
    	tmp.insert(*itr);
    }
    for(auto& i: tmp) ms.erase(ms.find(i));
    for(auto itr = ms.end();itr != ms.begin();){
    	itr--;
    	ll num = maki - 1;
    	if(itr->first + num * num - maki * maki > *(a.begin())){
    		num = itr->first + num * num - maki * maki - *(a.begin());
    		sum += num;
    		a.erase(a.begin());
    		maki--;
    	}
    }
    cout << sum << endl;
    return 0;
}
