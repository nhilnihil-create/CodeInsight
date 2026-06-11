#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;


int main() {
 int a,b;
 cin >>a >> b;
 int d = max(a+b,a-b);
 int ans = max(d,a*b);
 cout << ans << endl;
}