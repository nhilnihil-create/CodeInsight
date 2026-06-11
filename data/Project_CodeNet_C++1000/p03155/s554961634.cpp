#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
int n,h,w;
cin >> n >> h >> w;
int ans = (n-h+1)*(n-w+1);
cout << ans << endl;
}
