
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}

static void MSolProconOpenD();

#if 1
int main()
{
	MSolProconOpenD();
	fflush(stdout);
	return 0;
}
#endif


class MSolProconOpenDdata {
public:
	int nodeNo = 0;
	int edgeCount = 0;
	std::vector<int> edge;
	static bool asc_edgeCount(const MSolProconOpenDdata& a, const MSolProconOpenDdata& b) {
		return a.edgeCount < b.edgeCount;
	}
};

static void MSolProconOpenD()
{
	int N;
	int maxEdgeCount = 0, maxEdgeNode = 0;
	getint(N);
	std::vector<MSolProconOpenDdata> nodes(N);
	for (int i = 1; i < N; i++) {
		int a, b;
		getint(a, b); a--; b--;

		nodes[a].edge.push_back(b);
		nodes[a].edgeCount++;
		if (maxEdgeCount < nodes[a].edgeCount) {
			maxEdgeCount = nodes[a].edgeCount;
			maxEdgeNode = a;
		}

		nodes[b].edge.push_back(a);
		nodes[b].edgeCount++;
		if (maxEdgeCount < nodes[b].edgeCount) {
			maxEdgeCount = nodes[b].edgeCount;
			maxEdgeNode = b;
		}
	}

	std::vector<int> ci(N);
	for (int i = 0; i < N; i++) {
		nodes[i].nodeNo = i;

		getint(ci[i]);
	}

	std::sort(ci.begin(), ci.end(), std::greater<int>());

	std::vector<int> graph(N, -1);	//	ノードごとの点数を記録

	//	現時点の最高点をセット
	int valIdx = 0;
	graph[maxEdgeNode] = ci[valIdx];
	valIdx++;

	std::queue<MSolProconOpenDdata> que;
	que.push(nodes[maxEdgeNode]);

	while(!que.empty()) {
		//	現時点で一番辺の数が多いノード
		MSolProconOpenDdata top = que.front(); que.pop();
		std::vector<MSolProconOpenDdata> nextNodes;
		for (auto it = top.edge.begin(); it != top.edge.end(); it++) {
			if (graph[*it] == -1) {
				//	まだ点数割り当てが終わってない
				nextNodes.push_back(nodes[*it]);
			}
		}
		//	エッジの多い順にソート
		std::sort(nextNodes.begin(), nextNodes.end(), MSolProconOpenDdata::asc_edgeCount);
		//	順番に高い点をセット
		for (auto it = nextNodes.begin(); it != nextNodes.end(); it++) {
			graph[it->nodeNo] = ci[valIdx];
			valIdx++;
			//	キューに追加
			que.push(*it);
		}
	}

	//	計算済ノードの記録用
	std::vector<int> calc(N, 0);
	//	得点の計算
	LLONG ans = 0;
	que.push(nodes[0]);
	while (!que.empty()) {
		MSolProconOpenDdata node = que.front(); que.pop();
		int myPoint = graph[node.nodeNo];
		for (auto it = node.edge.begin(); it != node.edge.end(); it++) {
			ans += std::min(myPoint, graph[*it]);
			if (!calc[*it]) {
				que.push(nodes[*it]);
			}
		}
		calc[node.nodeNo] = 1;
	}
	printf("%lld\n", ans / 2);
	for (int i = 0; i < N; i++) {
		printf("%d ", graph[i]);
	}
	putchar('\n');
}
