#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    long double n, m, d;
    cin >> n >> m >> d;
    long double ans;
    if (d == 0){
        ans = double(m - 1) * double(1) / n;
    }
    else {
        ans = double(m - 1) * double(2 * (n - d)) / (n * n);
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}