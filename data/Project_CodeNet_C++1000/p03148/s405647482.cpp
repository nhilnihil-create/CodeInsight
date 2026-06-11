#include<bits/stdc++.h>
using namespace std;

long long N, K;
vector<long long> sushi[100005];
//          美味しさ , neta増える？
vector<pair<long long, long long> > top; 
int main(){
	cin >> N >> K;

	for(long long i = 0; i < N; i++){
		long long t,d;
		cin >> t >> d;t--;
		sushi[t].push_back(d);
	}

	for(long long i = 0; i < N; i++){
		sort(sushi[i].begin(), sushi[i].end(), greater<long long>());
		for(long long j = 0; j < sushi[i].size(); j++){
			if(j == 0){
				top.push_back(make_pair(sushi[i][j], 1));
			}else{
				top.push_back(make_pair(sushi[i][j], 0));
			}
		}
	}

	sort(top.begin(), top.end(), greater<pair<long long, long long> >());
	priority_queue<long long> rest;

	long long netanum = 0;
	long long oishisa = 0;
	for(long long i = 0; i < K; i++){
		oishisa+=top[i].first;
		netanum+=top[i].second;
	}
	for(long long i = K; i < top.size(); i++){
		if(top[i].second == 1){
			rest.push(top[i].first);
		}
	}

	long long ans = netanum * netanum + oishisa;

	for(long long i = K-1; i >= 0; i--){
		if(top[i].second == 1){
			continue;
		}
		if(rest.empty()){
			break;
		}
		long long oi = rest.top();
		rest.pop();
		oishisa -= top[i].first;
		oishisa += oi;
		netanum++;
		ans = max(ans, netanum * netanum + oishisa);
	}
	cout << ans << endl;
}

