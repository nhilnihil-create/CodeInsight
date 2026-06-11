#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;

int N, K, Q, A[2005], active[2005];

int par[2005];
vector<int> seg[2005];
vector<pi> v;
set<int> pars;

int find_par(int x){
	if (par[x] != x) par[x] = find_par(par[x]);
	return par[x];
}

void merg(int x, int y){
	int X = find_par(x), Y = find_par(y);
	if (X == Y) return;
	if (seg[X].size() < seg[Y].size()) swap(X,Y);
	par[Y] = X;
	vector<int> temp;
	merge(seg[X].begin(),seg[X].end(),seg[Y].begin(),seg[Y].end(),back_inserter(temp));
	seg[X] = temp;
	pars.erase(Y);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K >> Q;
	for (int i = 1; i <= N; ++i){
		cin >> A[i];
		v.push_back(pi(A[i],i));
		par[i] = i;
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int mini = 1e9+1;
	for (auto it : v){
		//cerr << it.first << ' ' << it.second << '\n';
		active[it.second] = 1;
		pars.insert(it.second);
		seg[it.second].push_back(it.first);
		if (active[it.second-1]) merg(it.second,it.second-1);
		if (active[it.second+1]) merg(it.second,it.second+1);
		vector<int> usable;
		//cerr << "YEET0\n";
		for (auto it2 : pars){
			//cerr << it2 << '\n';
			for (int i = 0; i < (int) (seg[it2].size())-K+1; ++i){
				usable.push_back(seg[it2][i]);
			}
		}
		//cerr << "YEET1\n";
		sort(usable.begin(),usable.end());
		if (usable.size() < Q) continue;
		else mini = min(mini,usable[Q-1]-usable[0]);
	}	
	cout << mini << '\n';
}