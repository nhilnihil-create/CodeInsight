#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define inf 1001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, p;
    cin >> a >> p;
    p += 3*a;
    cout << (int)p/2 << endl;

}