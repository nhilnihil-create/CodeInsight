#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> p;
vector<long long> y;

bool comp(int i, int j) {
  return y[i] < y[j];
}

int main(int argc, char* argv[]) {
  int N, M;
  cin >> N >> M;

  p.resize(M);
  y.resize(M);
  vector<long long> indices(M);
  for (int i = 0; i < M; ++i) {
    cin >> p[i] >> y[i];
    indices[i] = i;
  }

  sort(indices.begin(), indices.end(), comp);

  vector<long long> ret(M);
  map<long long, long long> m;
  for (int i = 0; i < M; ++i) {
    long long x;
    int index = indices[i];
    if (m.find(p[index]) == m.end()) {
      m[p[index]] = 1;
      x = 1;
    } else {
      ++m[p[index]];
      x = m[p[index]];
    }
    ret[index] = x;
  }

  for (int i = 0; i < M; ++i) {
    string head = to_string(p[i]);
    while (head.size() < 6) {
      head = '0' + head;
    }
    string tail = to_string(ret[i]);
    while (tail.size() < 6) {
      tail = '0' + tail;
    }
    cout << head << tail << endl;
  }

  return 0;
}