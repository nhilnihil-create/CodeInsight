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
int a,b,c,d;
cin >> a >> b >> c >> d;
string ans = "No";
if(abs(a-c)<=d) {
  ans = "Yes";
}
if(abs(a-b)<=d&&abs(c-b)<=d) {
  ans = "Yes";
}
cout << ans << endl;
return 0;
}
