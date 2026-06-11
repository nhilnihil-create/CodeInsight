#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 200005


#define PI 3.14159265358979323846264338327950

#define ll  long long int
vector<pair<ll, ll> > v;
multiset<ll> ms;
multiset<ll>::iterator it;
ll a[MAXX], b[MAXX];
ll mod = 1000000007;
char c[MAXX];
bool used[MAXX];
int main()
{
	FAST;
	memset(used, true, sizeof(used));
	ll  ans = 0, a1 = 0, a2 = 0, n;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a1;
		v.push_back({a1, i});
	}
	sort(v.begin(), v.end());
	while(!v.empty()){
        int x = v[0].first;
        int y = v[0].second;
        v.erase(v.begin());
        int s = 0;
        for(int i = 0; i < v.size(); i++){
            v[i].first -= x;
        }
        for(int i = 0; i < n; i++){
            if(used[i])
                s++;
            if(i && used[i] && used[i - 1])
                s--;
        }
        used[y] = false;
        ans += s * x;
    }
	cout << ans;
	
}