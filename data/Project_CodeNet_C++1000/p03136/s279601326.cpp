#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n; cin >> n;
  vector<int> data(n); REP(i,n) cin >> data[i];
  int sum = 0;
  sort(ALL(data));
  REP(i,n-1){
    sum += data[i];
  }
  if(data[n-1] < sum)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
} 