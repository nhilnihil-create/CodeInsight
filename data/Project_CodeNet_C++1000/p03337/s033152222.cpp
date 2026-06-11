#include <bits/stdc++.h>
#include <math.h>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;
const int mINF = -1001001001;


int main() {
int a,b,c,d,e;
cin >> a >> b;
c = a + b;
d = a - b;
e = a * b;
int ans = max(mINF,c);
ans = max(ans,d);
ans = max(ans,e);
cout << ans << endl;
return 0;
}
