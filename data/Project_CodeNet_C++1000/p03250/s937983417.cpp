#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{

int a, b, c;
cin >> a >> b >> c;

vector<int>vec = {a,b,c};
sort(vec.begin(), vec.end());

cout << vec.at(2) * 10 + vec.at(1) + vec.at(0) << endl;

return 0;
}