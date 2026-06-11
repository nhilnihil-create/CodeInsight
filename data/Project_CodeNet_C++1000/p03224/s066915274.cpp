#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int k = 0;
int N;

vector<vector<int>> G;

void print() {
   rep (i, k) {
      for (int x : G[i]) {
         cout << x+1 << " ";
      }
      puts("");
   }
}

signed main() {
   cin >> N;

   while (1) {
      if (N == k*(k-1)/2) {
         break;
      }
      if (N < k*(k-1)/2) {
         puts("No");
         return 0;
      }
      k++;
   }

   G = vector<vector<int>>(k, vector<int>(0));
   int pos = 1;
   rep (i, k) {
      repp (j, i+1, k) {
         G[i].push_back(pos);
         G[j].push_back(pos);
         pos++;
      }
   }

   cout << "Yes" << endl;
   cout << k << endl;
   rep (i, k) {
      cout << G[i].size();
      for (int x : G[i]) {
         cout << " " << x;
      }
      puts("");
   }


   return 0;
}