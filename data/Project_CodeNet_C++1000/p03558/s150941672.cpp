#include<cstdio>
#include<algorithm>
#include<deque>

using namespace std;

const int INF = 1 << 29;

int main(){
	int k; scanf("%d", &k);
	int d[100000];
	fill(d, d + k, INF); d[1] = 1;
	deque<int> q;
	q.push_back(1);
	while(!q.empty()){
		int t = q.front(); q.pop_front();
		if(d[(t * 10) % k] > d[t]){ q.push_front((t * 10) % k); d[(t * 10) % k] = d[t]; }
		if(d[(t + 1) % k] > d[t] + 1){ q.push_back((t + 1) % k); d[(t + 1) % k] = d[t] + 1; }
	}
	printf("%d\n", d[0]);
	return 0;
}