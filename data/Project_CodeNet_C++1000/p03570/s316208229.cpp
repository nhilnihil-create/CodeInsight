#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <deque>
using namespace std;

int sum[200010][26], dijk[200010], n[200010];

int main() {
	string S;
	cin >> S;
	for(int i=0; i<26; ++i){
		sum[0][i]=0;
		for(int j=0; j<S.size(); ++j){
			sum[j+1][i]=sum[j][i];
			if(S[j]-'a'==i) sum[j+1][i]=1-sum[j+1][i];
		}
	}
	unordered_map<int, vector<int>> ump;
	for(int i=0; i<=S.size(); ++i){
		n[i]=0;
		for(int j=0; j<26; ++j){
			n[i] += ((sum[i][j])<<j);
		}
		if(i==S.size()){
			ump[n[i]].clear();
		}
		ump[n[i]].emplace_back(i);
	}
	for(int i=1; i<=S.size(); ++i) dijk[i]=1e6;
	deque<int> dq{0};
	while(dq.front()<S.size()){
		int t=dq.front();
		dq.pop_front();
		for(int i=-1; i<26; ++i){
			int u=n[t];
			if(i>=0) u ^= (1<<i);
			auto itr=upper_bound(ump[u].begin(), ump[u].end(), t);
			if(itr!=ump[u].end()){
				int nx=*itr;
				if(dijk[nx]>dijk[t]+1){
					dijk[nx]=dijk[t]+1;
					dq.push_back(nx);
				}
			}
		}
	}
	cout << dijk[S.size()] << endl;
	return 0;
}