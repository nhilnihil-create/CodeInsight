#include<bits/stdc++.h>
using namespace std;

long long N, M;
//           id      ,  distance
vector<pair<long long, long long> >vec[100005];
long long pos[100005];
set<long long> done;

bool dfs(long long curpos){
	if(done.count(curpos) != 0)
		return true;
	done.insert(curpos);
	for(long long i = 0; i < vec[curpos].size(); i++){
		long long nextpos = vec[curpos][i].first;
		long long diff = vec[curpos][i].second;
		if(pos[nextpos] != INT_MAX && pos[nextpos] != pos[curpos] + diff){
			return false;
		}
		pos[nextpos] = pos[curpos] + diff;
		if(dfs(nextpos) == false){
			return false;
		}
	}
	done.insert(curpos);
	return true;
}

int main(){
	cin >> N >> M;
	for(long long i = 0; i < M; i++){
		long long L, R, D;
		cin >> L >> R >> D;
		L--;R--;
		vec[L].push_back(make_pair(R, D));
		vec[R].push_back(make_pair(L, -1*D));
	}

	for(long long i = 0; i < N; i++)
		pos[i] = INT_MAX;


	for(long long i = 0; i < N; i++){
		if(done.count(i) != 0)
			continue;
		pos[i] = 0;
		if(dfs(i) == false){
			cout << "No" << endl;
			return 0;
		}

	}

	cout << "Yes" << endl;
	return 0;
}