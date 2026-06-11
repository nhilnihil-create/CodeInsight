#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    double ave = 0;
    rep(i, n) {
        cin >> a[i];
        ave += a[i];
    }
    ave /= n;

    double len = INF;
    int ans = 0;
    rep(i, n){
        double tmp = abs(ave - a[i]);
        if(len > tmp){
            len = tmp;
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}
