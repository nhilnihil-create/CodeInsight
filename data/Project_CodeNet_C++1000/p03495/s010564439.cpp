#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <math.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) {
    int num;
    cin >> num;
    a.at(i) = num;
  }
  map<int, int> data;
  rep(i, n) {
    if (data.count(a.at(i))) {
      data.at(a.at(i))++;
    }
    else {
      data[a.at(i)] = 1;
    }
  }
  int datasize = data.size();
  vector<int> type(datasize);
  int counta = 0;
  for (pair<int, int> p : data) {
    int key = p.first;
    int value = p.second;
    type.at(counta) = value;
    counta++;
  }
  sort(type.begin(), type.end());
  int count = 0;
  int count_type = 0;
  while (k < datasize - count_type) {
    count += type.at(count_type);
    count_type++;
  }
  cout << count << endl;
}
