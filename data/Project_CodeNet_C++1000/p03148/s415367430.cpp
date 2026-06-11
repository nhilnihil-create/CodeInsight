#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
const int MOD = 1e9+7;
const int MOOD = 998244353;
typedef long long ll;
#define PI 3.14159265359
using namespace std;

bool newcoun[100001];
bool counter[100001];
bool firused[100001];
bool secused[100001];
int councoun[100001];

ll llmax(ll x, ll y){
	if (x > y) return x;
	return y;
}


int main(){
	ll n, k, maximum = 0;
	cin >> n >> k;
	vector<pair<ll, ll> > vec(n);
	for (int i = 0; i < n; i++){
		cin >> vec[i].second >> vec[i].first;
		newcoun[vec[i].second] = true;
	} 
	for (int i = 0; i <= n; i++){
		if (newcoun[i]){
			maximum++;
		}
	}
	sort(vec.begin(), vec.end(), greater<pair<int, int> >());

	ll sumoisi = 0;
	for (int i = 0; i < k; i++){
		sumoisi += vec[i].first;
		counter[vec[i].second] = true;
		councoun[vec[i].second]++;
		if (firused[vec[i].second]){
			secused[vec[i].second] = true;
		}else{
			firused[vec[i].second] = true;
		}
	}
	ll coun = 0;

	for (int i = 1; i <= n; i++){
		if (counter[i]){
			coun++;
		}
	}

	sumoisi += coun*coun;
	ll ans = sumoisi;

	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
	priority_queue<pair<ll, ll> > pq2; 
 
	for (int i = k-1; i >= 0; i--){
		if (secused[vec[i].second] && councoun[vec[i].second] > 1){
			pq.push(make_pair(vec[i].first, vec[i].second));
			councoun[vec[i].second]--;
		}
	}

	for (int i = k; i < n; i++){
		if (!firused[vec[i].second]){
			pq2.push(make_pair(vec[i].first, vec[i].second));
		}
	}
	for (int i = coun; i < maximum; i++){
		if (pq.empty()){
			cout << ans << endl;
			return 0;
		}
		pair<ll, ll> p = pq.top();
		pq.pop();
		sumoisi -= p.first;
		if (pq2.empty()){
			cout << ans << endl;
			return 0;
		}
		pair<ll, ll> p2 = pq2.top();
		while(firused[p2.second]){
			if (pq2.empty()){
				cout << ans << endl;
				return 0;
			}
			pq2.pop();
			p2 = pq2.top();
		}
		pq2.pop();
		firused[p2.second] = true;
		sumoisi += p2.first;
		sumoisi += (i+1)*(i+1);
		sumoisi -= i*i;
		ans = max(ans, sumoisi);
	}

	cout << ans << endl;
	return 0;
}