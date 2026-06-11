#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;


const int maxV = 300000;
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
    //printf("start: %d, end: %d, diameter: %d\n", start, end, maxDist);
    return maxDist;
}

int main(int argc, char const *argv[]) {
  int N, a, b;
  std::cin >> N;
  for(int i=0;i<N-1;i++){
    std::cin >> a >> b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }
  int ans = getTreeDiameter();
  std::cout << (ans%3==1?"Second":"First") << '\n';
  return 0;
}
