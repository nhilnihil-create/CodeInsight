#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define MOD ((LL)1e9+7) 
#define INF ((LL)1e9+7)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define BIT(x) (1LL << (x))
using namespace std;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

LL modpow(LL x, LL b){
	LL res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

LL modinv(LL x){
	return modpow(x, MOD-2);
}

int main(){
	int N, M;
	cin >> N >> M;
	vector<vector<PLL>> road(N);
	REP(i, M){
		LL a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		road[a].push_back(PLL({b, c}));
		road[b].push_back(PLL({a, -c}));
	}
	vector<bool> used(N, false);
	vector<LL> pos(N);
	REP(i, N){
		if(used[i])continue;
		used[i]=true;
		stack<PLL> st;
		st.push({i, 0});
		pos[i] = 0;
		while(!st.empty()){
			PLL d = st.top();
			st.pop();
			foreach(j, road[d.first]){
				LL np = j.second + d.second;
				if(used[j.first]){
					if(pos[j.first] != np){
						cout << "No" << endl;
						return 0;
					}
					continue;
				}
				used[j.first] = true;
				pos[j.first] = np;
				st.push({j.first, np});
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
