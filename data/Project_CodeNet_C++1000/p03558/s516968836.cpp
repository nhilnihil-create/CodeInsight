#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int lli;

template<class T>bool chmax(T &a, const T &b) { if( a < b ) { a = b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if( b < a ) { a = b; return 1; } return 0;}

#ifdef LOCAL
	#define eprintf(...) printf(__VA_ARGS__)
#else 
	#define eprintf(...) 1
#endif

#define ROUNDUP(a, b) 		( ((a) + ((b) - 1) ) / b)
#define SET_ZERO(a)	 		( memset((a), 0, sizeof(a)))
#define SET_NUM_ARRAY(a,b)	( memset((a), b, sizeof(a)))

const int MAX_K = 1000*100;
int dist[MAX_K];
typedef pair<int, int> node;
int BFS01(int k) {
	for (int i = 0; i < k; i++) {
		dist[i] = 1001001001;
	}
	deque<node> deq;
	deq.push_front(node(1,1));

	while (!deq.empty()) {
		node v = deq.front();
		deq.pop_front();
		if (v.first == 0) return v.second;
		dist[v.first] = 1;

		int next = (v.first + 1) % k;
		if (dist[next] > dist[v.first] + 1) {
			deq.push_back(node(next,v.second+1));
		}

		next = (v.first * 10) % k;
		if (dist[next] > dist[v.first]) {
			deq.push_front(node(next, v.second));
		}
	}
}

int main() {
	int K;
	scanf("%d", &K);
	printf("%d\n", BFS01(K));
}
