#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define dbg(x) cerr << #x << ": " << x << endl;
#define dbg2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define dbg3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define dbgB(value, size) cerr<<#value<<": "<<bitset<size>(value) << endl;
#define line() cerr << "---------------" << endl;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

template<typename T>
void printA(vector<T> &printArray, char between = ' ') {
   int paSize = printArray.size();
   for (int i = 0; i < paSize; i++) { cerr << printArray[i] << between;}
   if (between != '\n') {cerr << endl;}
}

// ------------------------------------------------------------------------------------------

int cnt[2][202020];

int main() {
   int n, m;
   cin >> n >> m;
   string s;
   cin >> s;
   int a[n];
   rep (i, n) {
      a[i] = (s[i]=='A');
   }
   vec<int> v[n];
   rep (i, m) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      v[x].push_back(y);
      v[y].push_back(x);
      cnt[a[x]][y]++;
      cnt[a[y]][x]++;
   }
   bool ok[n];
   queue<int> q;
   rep (i, n) {
      ok[i] = (cnt[1][i] > 0 && cnt[0][i] > 0);
      if (!ok[i]) q.push(i);
   }
   while (q.size()) {
      int x = q.front(); q.pop();
      for (auto &u : v[x]) {
         if (!ok[u]) continue;
         if (--cnt[a[x]][u] == 0) {
            ok[u] = false;
            q.push(u);
         }
      }
   }

   rep (i, n) {
      if (ok[i]) {
         cout << "Yes"<< endl;
         return 0;
      }
   }
   puts("No");

   return 0;
}