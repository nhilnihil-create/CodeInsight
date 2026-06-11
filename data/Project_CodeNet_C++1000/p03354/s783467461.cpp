#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main() {
	int N,M; cin>>N>>M;
	vector<int> p(N);
	for (int i=0; i<N; i++)
		cin>>p[i], p[i]--;
	UnionFind uf(N);
	for (int i=0; i<M; i++) {
		int x,y; cin>>x>>y; x--; y--;
		uf.unionSet(x,y);
	}
	int ret=0;
	map<int,vector<int>> gp;
	for (int i=0; i<N; i++)
		gp[uf.findSet(i)].push_back(i);
	for (auto it : gp) {
		set<int> cur;
		for (auto it2 : it.second)
			cur.insert(p[it2]);
		for (auto it2 : it.second)
			if(cur.count(it2))
				ret++;
	}
	cout<<ret<<"\n";
  return 0;
}