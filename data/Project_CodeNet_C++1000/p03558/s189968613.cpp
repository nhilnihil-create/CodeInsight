#include<bits/stdc++.h>
#include<boost/variant.hpp>
using namespace std;
typedef long long ll;
typedef vector<boost::variant<bool, ll, int, string, double>> any;
template<typename T> inline void pr(const vector<T> &xs){
	for(int i=0; i<xs.size()-1; i++) cout<<xs[i]<<" ";
	(xs.empty()?cout:(cout<<xs[xs.size()-1]))<<endl;
}
template<typename T> inline void debug(const vector<T> &xs){
#ifdef DEBUG
	pr(xs);
#endif
}

int main(){
	int K;
	cin >> K;

	vector<int> dist(K, 1e8);
	dist[1] = 0;
	deque<int> deq;
	deq.push_front(1);
	while(!deq.empty()){
		int x = deq.front();
		deq.pop_front();
		if(dist[x%K]+1 < dist[(x+1)%K]){
			deq.push_back((x+1)%K);
			dist[(x+1)%K] = dist[x%K]+1;
		}
		if(dist[x%K] < dist[10*x%K]){
			deq.push_front(10*x%K);
			dist[10*x%K] = dist[x%K];
		}
	}

	cout << dist[0]+1 << endl;


	return 0;
}
