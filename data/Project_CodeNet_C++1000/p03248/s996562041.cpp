#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
  string str;
  cin >> str;

  int vertexc = str.size();

  if (str[vertexc - 1] != '0') {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 1; i <= vertexc - 1; i++) {
    if (str[i - 1] != str[vertexc - i - 1]) {
      cout << -1 << endl;
      return 0;
    }
  }

  if (str[1 - 1] != '1') {
    cout << -1 << endl;
    return 0;
  }

  vector<int> allowed;
  for (int i = 2; i <= vertexc; i++) {
    if (str[i - 1] == '1') {
      allowed.push_back(i);
    }
  }

  int curRoot = 1;
  int curVertexc = 1;
  for (int v : allowed) {
    int newRoot = curVertexc + 1;
    curVertexc++;
    cout << curRoot << " " << newRoot << endl;
    curRoot = newRoot;
    
    while (curVertexc < v) {
      int u = curVertexc + 1;
      curVertexc++;
      cout << curRoot << " " << u << endl;
    }
  }

  while (curVertexc < vertexc) {
    int u = curVertexc + 1;
    curVertexc++;
    cout << curRoot << " " << u << endl;
  }
}
