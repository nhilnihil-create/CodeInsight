#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
#define reps(i, S, E) for (ll i = (S); i <= (E); i++)
#define rep(i, N) reps(i, 0, N-1)
#define deps(i, E, S) for (ll i = (E); i >= (S); i--)
#define dep(i, N) deps(i, N-1, 0)

//AtCoder Beginner Contest 116 - D
struct LLPair {
	ll t = 0;
	ll d = 0;
	LLPair() {}
	LLPair(ll t, ll d) {
		this->t = t;
		this->d = d;
	}
};

bool operator< (const LLPair &p1, const LLPair &p2) {
	return p1.d > p2.d;
};

int main() {
	ll N;
	scanf("%lld", &N);
	ll K;
	scanf("%lld", &K);
	vector<LLPair> pair(N);
	priority_queue<LLPair> pq; //�l�^�̔��������Ⴂ��
	vll count(N, 0);
	rep(i, N) {
		ll t;
		scanf("%lld", &t);
		ll d;
		scanf("%lld", &d);
		pair[i].t = t - 1;
		pair[i].d = d;
	}

	std::sort(pair.begin(), pair.end(), [](const LLPair &a, const LLPair &b) {
		return a.d > b.d; //�~���ɂ���ɂ� > �Ƃ���
	});

	ll sum_d = 0;
	ll kind = 0;

	rep(i, K) {
		sum_d += pair[i].d;
		if (count[pair[i].t] == 0) {
			kind++;
		}
	
		count[pair[i].t]++;
		pq.push(pair[i]);
	}

	ll result = sum_d + kind * kind;

	ll iPair = K;
	while (pq.empty() == false) {
		//��菜�����̂�I��
		LLPair item = pq.top();
		pq.pop();

		if (count[item.t] == 1) {
			//���X�P�̏ꍇ�́A��菜���Ǝ�ސ�������̂ŃX�L�b�v
			continue;
		}

		count[item.t]--;
		sum_d -= item.d;

		//pair[i]�����ɓ����
		while (iPair < N) {
			if (count[pair[iPair].t] > 0) {
				//���łɂ��̎�ނ̂��̂����݂���ꍇ�͎�ސ��������Ȃ��̂ŃX�L�b�v
				iPair++;
				continue;
			}

			count[pair[iPair].t]++;
			sum_d += pair[iPair].d;
			kind++;

			result = max(result, sum_d + kind * kind);

			iPair++;
			break;
		}

		if (iPair == N) {
			break;
		}
	}

	printf("%lld\n", result);
}


//AtCoder Beginner Contest 065 - D
/*
struct LLPoint {
	ll x = 0;
	ll y = 0;
	ll no = 0;
	LLPoint() {}
	LLPoint(ll no, ll x, ll y) {
		this->no = no;
		this->x = x;
		this->y = y;
	}
};

// �O���t�e���v���[�g
template<typename T>
struct edge {
	int src, to;
	T cost;
	edge(int to, T cost) : src(-1), to(to), cost(cost) {}
	edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}
	edge &operator=(const int &x) {
		to = x;
		return *this;
	}
	operator int() const { return to; }
};
template<typename T>
using Edges = vector<edge<T>>;
template<typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template<typename T>
using Matrix = vector<vector<T >>;

//Union-Find : O(��(N))
struct UnionFind {
	vector<int> data;
	UnionFind(int sz) {
		data.assign(sz, -1);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return (false);
		if (data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return (true);
	}
	int find(int k) {
		if (data[k] < 0) {
			return (k);
		}
		return (data[k] = find(data[k]));
	}
	int size(int k) {
		return (-data[find(k)]);
	}
};

//�ŏ��S���(Kruskal) : O(E * logV)
template<typename T>
T kruskal(Edges<T> &edges, int V) {
	sort(begin(edges), end(edges), [](const edge<T> &a, const edge<T> &b) {
		return (a.cost < b.cost);
	});
	UnionFind tree(V);
	T ret = 0;
	for (auto &e : edges) {
		if (tree.unite(e.src, e.to)) ret += e.cost;
	}
	return (ret);
}

int main() {
	ll N;
	scanf("%lld", &N);
	vector<LLPoint> xSort(N);
	vector<LLPoint> ySort(N);
	rep(i, N) {
		ll x;
		scanf("%lld", &x);
		ll y;
		scanf("%lld", &y);
		xSort[i].no = i;
		xSort[i].x = x;
		xSort[i].y = y;
		ySort[i].no = i;
		ySort[i].x = x;
		ySort[i].y = y;
	}

	std::sort(xSort.begin(), xSort.end(), [](const LLPoint &a, const LLPoint &b) {
		return a.x < b.x; //�~���ɂ���ɂ� > �Ƃ���
	});

	std::sort(ySort.begin(), ySort.end(), [](const LLPoint &a, const LLPoint &b) {
		return a.y < b.y; //�~���ɂ���ɂ� > �Ƃ���
	});

	Edges<ll> edges;

	rep(i, N - 1) {
		edges.emplace_back(xSort[i].no, xSort[i + 1].no, abs(xSort[i].x - xSort[i + 1].x));
		edges.emplace_back(ySort[i].no, ySort[i + 1].no, abs(ySort[i].y - ySort[i + 1].y));
	}

	ll result = kruskal(edges, (int)N);

	printf("%lld\n", result);
}
*/
