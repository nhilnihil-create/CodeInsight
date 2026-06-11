#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> m1;
map<int, int> m2;

bool comp1(int a, int b) {
  return m1[a] > m1[b];
}


bool comp2(int a, int b) {
  return m2[a] > m2[b];
}

int main(int argc, char* argv[]) {
  int n;
  cin >> n;

  int v[n];
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  vector<int> a;
  for (int i = 0; i < n; i += 2) {
    if (m1.find(v[i]) == m1.end()) {
      m1[v[i]] = 0;
      a.push_back(v[i]);
    }
    ++m1[v[i]];
  }

  vector<int> b;
  for (int i = 1; i < n; i += 2) {
    if (m2.find(v[i]) == m2.end()) {
      m2[v[i]] = 0;
      b.push_back(v[i]);
    }
    ++m2[v[i]];
  }

  sort(a.begin(), a.end(), comp1);
  sort(b.begin(), b.end(), comp2);

  long long ret = 0;
  if (a[0] == b[0]) {
    if (a.size() == 1 && b.size() == 1) {
      ret = n / 2;
    } else if (a.size() == 1 && b.size() > 1) {
      ret = n - m1[a[0]] - m2[b[1]];
    } else if (b.size() == 1 && a.size() > 1) {
      ret = n - m1[a[1]] - m2[b[0]];
    } else {
      ret = n - max(m1[a[0]] + m2[b[1]], m1[a[1]] + m2[b[0]]);
    }
  } else {
    ret = n - m1[a[0]] - m2[b[0]];
  }

  cout << ret << endl;

  return 0;
}