#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <cmath>
#include <utility> // pair make_pair
#include <algorithm>
#include <functional>
#include <iomanip>
#include <climits> // LLONG_MAX, LLONG_MIN, INT_MIN, INT_MAX
#include <assert.h>

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define ll long long
//#define int ll
#define INF INT_MAX/10
#define MOD 1000000007

using namespace std;
using Pi = pair<int, int>;
using Graph = vector<vector<int> >;
using WeightGraph = vector<vector<Pi> >;

string Input[100100];
const string MINUSINF = "-";


void chmax(string &a, string b) {
    if (a == MINUSINF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}

int main() {
  int N, M; cin >> N >> M;
  vector<int> Use;
  for (int i = 0; i < M; i++) {
    int a; cin >> a;
    Use.push_back(a);
  }
  int A[10] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  for (int i = 0; i < 100100; i++) {
    Input[i] = MINUSINF;
  }
  
  Input[0] = "";

  for (int i = 0; i < N; i++) {
    if (Input[i] == "-") continue;
    for (auto x: Use) {
      chmax(Input[i + A[x]], Input[i] + to_string(x));
    }
  }

  cout << Input[N] << endl;
}
