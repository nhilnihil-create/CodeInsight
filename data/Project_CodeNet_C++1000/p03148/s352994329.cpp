#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, K; cin >> N >> K;
	priority_queue<pair<int, int>> dt, mdt;

	for(int i=0; i<N; ++i){
		int t, d; cin >> t >> d;
		dt.push(make_pair(d, t));
	}

	vector<long long> sums(K+1, -1);
	long long sum = 0;
	map<int, int> kind;
	for(int i=0; i<K; ++i){
		int d = dt.top().first, t = dt.top().second;
		dt.pop();
		mdt.push(make_pair(-d, t));
		++kind[t];
		sum += d;
	}
	sums[kind.size()] = sum + kind.size()*kind.size();
	// cout << kind.size() << " : " << sum << " "<< sums[kind.size()] << endl;

	for(int i=kind.size()+1; i<=K; ++i){
		bool f = true;
		while(f){
			vector<pair<int, int>> mem;
			auto top = mdt.top(); mdt.pop();

			if(kind[top.second] > 1){
				--kind[top.second];
				dt.push(top);
				for(auto work : mem){
					mdt.push(work);
				}
				sum += top.first;
				break;
			}else{
				mem.push_back(top);
			}
			if(mdt.empty()) f = false;
		}
		while(f){
			vector<pair<int, int>> mem;
			auto top = dt.top(); dt.pop();

			if(kind.find(top.second) == kind.end()){
				++kind[top.second];
				mdt.push(top);
				for(auto work : mem){
					dt.push(work);
				}
				sum += top.first;
				break;
			}else{
				mem.push_back(top);
			}
			if(dt.empty()) f = false;
		}
		if(!f) break;
		sums[i] = sum + kind.size()*kind.size();
		// cout << kind.size() << " : " << sum << " "<< sums[kind.size()] << endl;
	}

	sort(sums.begin(), sums.end(), greater<long long>());
	cout << sums[0] << endl;
}
