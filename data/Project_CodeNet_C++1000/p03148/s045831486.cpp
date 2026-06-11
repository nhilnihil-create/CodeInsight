#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;



int main(){
	int N,K;
	cin >> N >> K;
	vector<P> a(N);
	vector<ll> f(N + 1,0);
	for(int i = 0; i < N; i++) {
		ll t,d;cin>>t>>d;
		a[i] = mp(d,t);
	}
	sort(RALL(a));
	priority_queue<ll,vector<ll>,greater<ll>> que1;
	vector<bool> used(N + 1,false);//一個使ってるか
	ll sum = 0;
	ll kind = 0;
	ll res = 0;
	for(int i = 0; i < N; i++) {
		if (i < K){
			if (!used[a[i].sc]){
				sum += a[i].fs;
				kind ++;
				used[a[i].sc] = true;
			}
			else{
				sum += a[i].fs;
				que1.push(a[i].fs);
			}
			f[kind] = sum;
			res = max(res,sum + kind * kind);
		}
		else{
			if (que1.empty())break;
			if (!used[a[i].sc]){
				sum -= que1.top();
				sum += a[i].fs;
				kind++;
				used[a[i].sc] = true;
				que1.pop();
				f[kind] = sum;
				res = max(res,sum + kind * kind);
			} 
		}
	}
	cout << res << endl;
	return 0;
}
