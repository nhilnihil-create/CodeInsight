#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

struct state{
	Long len, link;
	map<char,int> next;
	state(){}
	state(Long len, Long link) : len(len), link(link){}
};

struct suffixAutomaton{
	vector<state> st;
	Long sz, last;
	
	suffixAutomaton(){}
	suffixAutomaton(Long n){
		st.resize(n << 1ll);
		last = 0;
		st[0].len = 0;
		st[0].link = -1;
		sz = 1;
	}
	
	void addChar(char c){
		Long cur = sz++;
		st[cur].len = st[last].len + 1;
		Long p = last;
		while(p != -1 && !st[p].next.count(c)){
			st[p].next[c] = cur;
			p = st[p].link;
		}
		if(p == -1){
			st[cur].link = 0;
		}else{
			Long q = st[p].next[c];
			if(st[p].len + 1 == st[q].len){
				st[cur].link = q;
			}else{
				Long clone = sz++;
				st[clone].len = st[p].len + 1;
				st[clone].next = st[q].next;
				st[clone].link = st[q].link;
				while(p != -1 && st[p].next[c] == q){
					st[p].next[c] = clone;
					p = st[p].link;
				}
				st[q].link = st[cur].link = clone;
			}
		}
		last = cur;
	}
	
	void build(string &s){
		for(char c : s) addChar(c);
		return;
	}
};


const Long MX = 1e4 + 10;
suffixAutomaton sa;
Long memo[MX];
bool used[MX];
bool ok;
string ans;

Long dp(Long u){
	if(used[u]) return memo[u];
	used[u] = true;
	memo[u] = 1;
	for(auto par : sa.st[u].next){
		memo[u] += dp(par.second);
	}
	return memo[u];
}

void reconstruct(Long u, Long l, Long r, Long k){
	if(l == k){
		ok = true;
		return;
	}
	Long aux = 1;
	for(auto par : sa.st[u].next){
		Long v = par.second;
		if(l + aux <= k && k <= l + aux + memo[v] - 1){
			reconstruct(v, l + aux, l + aux + memo[v] - 1, k);
			if(ok){
				ans += par.first;
				break;
			}
		}
		aux += memo[v];
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(10);
	cout << fixed;

	string s;
	cin >> s;
	Long k;
	cin >> k;
	k++;
	
	sa = suffixAutomaton(s.size());
	sa.build(s);
	dp(0);
	ok = false;
	ans = "";
	reconstruct(0,1,memo[0],k);
	reverse(ans.begin(),ans.end());
	cout << ans << "\n";
	return 0;
}
