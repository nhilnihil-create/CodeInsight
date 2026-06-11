#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[200001];
vector<bool> visited(200001, false);
int diameter;
int v0;

void visit(const int vertex, int d)
{
  visited[vertex] = true;
  if (diameter < d) {
    diameter = d;
    v0 = vertex;
  }
  for (auto&& v : graph[vertex]) {
    if (!visited[v])
      visit(v, d + 1);
  }
  visited[vertex] = false;
}

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }
  visit(1, 0);
  visit(v0, 0);
  cout << (diameter % 3 == 1 ? "Second" : "First") << endl;
}
