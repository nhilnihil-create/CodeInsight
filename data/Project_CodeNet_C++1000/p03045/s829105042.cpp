#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

class UnionFind {
private:
	vector< int > data;
	int num_of_g;
	
public:
	UnionFind(int n) : data(n, -1), num_of_g(n) {}
	
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		
		if (x == y) return 0;
		
		if (data[y] < data[x]) swap(x, y);
		data[x] += data[y]; data[y] = x;
		--num_of_g;
		
		return 1;
	}
	
	bool sameSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
	int getNumOfG() { return num_of_g; }
};

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);
    for_(i,0,M) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        uf.unionSet(x, y);
    }

    cout << uf.getNumOfG() << endl;
}