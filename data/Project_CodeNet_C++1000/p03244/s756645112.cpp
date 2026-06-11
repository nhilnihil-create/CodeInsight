#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
  int num;
  int count;
};

bool node_cmp(const struct node &p, const struct node &q) {
  return p.count < q.count;
}

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  map<int, int> odd;
  map<int, int> even;

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      even[v[i]]++;
    } else {
      odd[v[i]]++;
    }
  }

  int sum = 0;
  for (auto var : even) {
    sum += var.second;
  }
  vector<node> even_v;
  for (auto var : even) {
    struct node tmp;
    tmp.num = var.first;
    tmp.count = sum - var.second;
    even_v.push_back(tmp);
  }

  sum = 0;
  for (auto var : odd) {
    sum += var.second;
  }
  vector<node> odd_v;
  for (auto var : odd) {
    struct node tmp;
    tmp.num = var.first;
    tmp.count = sum - var.second;
    odd_v.push_back(tmp);
  }

  sort(even_v.begin(), even_v.end(), node_cmp);
  sort(odd_v.begin(), odd_v.end(), node_cmp);

  int output = 0;
  if (odd_v[0].num == even_v[0].num) {
    output =
        min(odd_v[0].count + even_v[1].count, odd_v[1].count + even_v[0].count);
    if (output == 0) {
      output = n / 2;
    }

  } else {
    output = odd_v[0].count + even_v[0].count;
  }

  cout << output << endl;
  return 0;
}
