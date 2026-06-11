#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    vector<int> a;
    rep(i, 4){
        int p;
        cin >> p;
        a.push_back(p);
    }
    sort(a.begin(), a.end());
    int check[4] = {1, 4, 7, 9};
    bool flag = true;
    rep(i, 4) flag &= (check[i] == a[i]);
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}