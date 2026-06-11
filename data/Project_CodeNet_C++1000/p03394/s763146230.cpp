#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

// ref : https://atcoder.jp/contests/agc022/submissions/10229377

int a[2][8]={
    {2,10,3,9,4,8,6,12},
	{6,2,10,3,9,4,8,12}
};

int main(){
    int n;
    cin >> n;
    if (n == 3){
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }
	rep(i, n){
        cout << a[n&1][i&7] << " ";
        a[n&1][i&7] += 12;
	}
    cout << endl;
    return 0;
}
