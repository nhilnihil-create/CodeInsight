#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <set>
#include <assert.h>
#include <stdio.h>
#define REP(i,n) for(ll i=0;i<(n);i++)
#define MOD 1000000007
#define int long long
#ifdef int
const long long INF = LLONG_MAX / 10;
#else
const int INF = 1010101010;
#endif
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > mat;
typedef pair<int, int> P;
//typedef pair<double, double> P;
const int dx[9] = {-1, 0, 0, 1, -1, -1, 1, 1, 0};
const int dy[9] = {0, -1, 1, 0, -1, 1, -1, 1, 0};
 
string S;
int N;
int num[3];
 
signed main()
{
  cin >> S;
  N = S.length();
  REP(i,N) num[S[i]-'a']++;

  if (N == 1) {
    cout << "YES" << endl;
    return 0;
  }

  if (N == 4) {
    int two = 0;
    REP(i,3) {
      if (num[i] >= 2) two++;
    }
    if (two >= 2) {
      cout << "NO" << endl;
      return 0;
    }
  }

  if (N > 4) {
    REP(i,3) {
      if ((N + 2) / 3 < num[i]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  } else {
    REP(i,3) {
      if (num[i] > N / 2) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}