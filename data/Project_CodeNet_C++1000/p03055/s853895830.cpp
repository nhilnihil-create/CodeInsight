#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

const int maxV = 202020;

vector<int> G[maxV]; // 頂点情報のみのグラフ

// treeDFS(親, 現在地, 根から現在地までの距離, 根からの最大の距離, 根から最大の距離となる頂点
void treeDFS(int from, int current, int dist, int &maxDist, int &maxVertex) {
    // 距離と終点を更新
    if (dist > maxDist) {
        maxDist = dist;
        maxVertex = current;
    }

    for (auto to : G[current]) {
        // 逆流を防ぐ
        if (to == from) continue;
        treeDFS(current, to, dist + 1, maxDist, maxVertex);
    }
}

int getTreeDiameter() {
    int start = 0, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    start = end, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    return maxDist;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	int diam = getTreeDiameter();
	if(diam % 3 == 1){
		cout << "Second" << endl;
	}else{
		cout << "First" << endl;
	}

}
