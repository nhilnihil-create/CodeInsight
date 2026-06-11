#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[200001];
vector<bool> visited(200001, false);

pair<int, int> visit(int vertex)
{
  int d(0), v(vertex);
  visited[vertex] = true;
  for (auto&& vn : edge[vertex]) {
    if (!visited[vn]) {
      auto p = visit(vn);
      if (d <= p.first) {
        d = p.first + 1;
        v = p.second;
      }
    }
  }
  visited[vertex] = false;
  return {d, v};
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    edge[v1].push_back(v2);
    edge[v2].push_back(v1);
  }
  cout << (visit(visit(1).second).first % 3 == 1 ? "Second" : "First") << endl;
}
