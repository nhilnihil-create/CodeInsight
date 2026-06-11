#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool Ok(vector<pair<char, char> >& Q, string& N, int cur) {
  int n = N.size(), n_q = Q.size();
  for (int i = 0; i < n_q; i++) {
    if (Q[i].first == N[cur]) {
      cur += (Q[i].second == 'L') ? -1 : 1;
    }
    if (cur < 0 || cur >= n) {
      return true;
    }
  }
  return false;
}

int SearchLeft(vector<pair<char, char> >& Q, string& N) {
  int left = 0, right = N.size();
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (Ok(Q, N, mid)) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  return left;
}

int SearchRight(vector<pair<char, char> >& Q, string& N) {
  int left = 0, right = N.size();
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (Ok(Q, N, mid)) {
      right = mid;
    }
    else {
      left = mid;
    }
  }
  return left;
}
int main() {
  ios::sync_with_stdio(false);
  int n, q;
  string N;
  vector<pair<char, char> > Q;
  cin >> n >> q >> N;
  for (int i = 0; i < q; i++){
    char l, r;
    cin >> l >> r;
    Q.push_back(make_pair(l, r));
  }
  int left = SearchLeft(Q, N);
  int right = SearchRight(Q, N);
  if (left >= right) {
    cout << 0;
  }
  else {
    if (Ok(Q, N, right)) {
      cout << right - left - 1;
    }
    else {
      cout << right - left;
    }
     
  }
  return 0;
}

