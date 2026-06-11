	#include <bits/stdc++.h>
	using namespace std;

	typedef long long ll;
	typedef vector<int> vi;
	typedef pair<int,int> pi;

	#define F first
	#define S second
	#define PB push_back
	#define MP make_pair
	#define what_is(x) cerr << #x << " is " << x << endl;
	#define MT make_tuple
	#define eb emplace_back
	#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

	#define REP(i,a,b) for (int i = a; i <= b; i++)
	#define FOR(i,n) for (int i=0;i < n ; i++)
	#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

	void err(istream_iterator<string> it) {}
	template<typename T, typename... Args>
	void err(istream_iterator<string> it, T a, Args... args) {
		cerr << *it << " = " << a << endl;
		err(++it, args...);
	}
	clock_t startTime;
	long double getTime(){
		return (long double)(clock()-startTime)/CLOCKS_PER_SEC;
	}

	bool compare(pair<ll,int> a,pair<ll,int> b){
		return a.F < b.F;
	}

	bool compare1(pair<string,int>a ,pair<string, int> b){
		return a.S<b.S;
	}

	int main(){
		startTime=clock();
		ll n;
		ll m;
		ll a;
		ll b;
		cin >> n >> m;
		std::vector<pair<ll,int>> v[n];
		FOR(i,m){
			cin >> a >> b;
			v[a-1].eb(MP(b,i+1)); 
		}
		FOR(i,n){
			sort(v[i].begin(),v[i].end(),compare);
		}
		std::vector<pair<string,int>> w;
		FOR(i,n){
			FOR(j,v[i].size()){
				string s=to_string(j+1);
				string t=to_string(i+1);
				int len1=6-s.length();
				int l2=6-t.length();
				string ans1(len1,'0');
				string ans2(l2,'0');
				string ans=ans2+t+ans1+s;
				w.eb(MP(ans,v[i][j].S));
			}
		}
		sort(w.begin(),w.end(),compare1);
		for(auto x : w){
			cout << x.F <<"\n";
		}

		return 0;
	}