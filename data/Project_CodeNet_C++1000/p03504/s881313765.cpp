#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int N,C;
	cin >> N >> C;

	vector<T> stc(N);
	for(int i = 0;i < N;i++){
		int s,t,c;
		cin >> s >> t >> c;
		c--;
		stc[i] = T(s,t,c);
	}
	sort(stc.begin(),stc.end());
	vector<vector<P>> st(C);
	for(int i = 0;i < N;i++){
		int s,t,c;
		tie(s,t,c) = stc[i];
		st[c].push_back(P(s,t));
	}
	vector<P> st1;
	for(int i = 0;i < C;i++){
		for(int j = 0;j < st[i].size();j++){
			int k = j;
			int nowt = st[i][j].second;
			int nows = st[i][j].first;
			while(k+1 < st[i].size() && st[i][k+1].first == nowt){
				nowt = st[i][k+1].second;
				k++;
			}
			st1.push_back(P(nows,nowt));
			j = k;
		}
	}
	sort(st1.begin(),st1.end());
	multiset<int> mst;
	mst.insert(st1[0].second);
	for(int i = 1;i < st1.size();i++){
		int nows = st1[i].first;
		int nowt = st1[i].second;
		auto p = mst.lower_bound(nows);

		if(p != mst.begin()){
			p--;
			mst.erase(p);
		}
		mst.insert(nowt);
	}
	cout << mst.size() << endl;
}
