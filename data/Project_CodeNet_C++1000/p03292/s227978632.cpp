#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    vector<int> x(3);
    rep(i, 3) cin >> x[i];
    sort(x.begin(), x.end());
    int mi = 1001001001;
    do{
        int res = abs(x[1]-x[0]) + abs(x[2]-x[1]);
        mi = min(res, mi);
    } while (next_permutation(x.begin(), x.end()));
    cout << mi;
}
