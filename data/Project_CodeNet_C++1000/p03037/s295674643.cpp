#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int n, m;
    cin >> n >> m;
    int l[m], r[m];
    int mx = n;
    int mn = 1;
    rep(i, m) {
        cin >> l[i] >> r[i];
        mx = min(mx, r[i]);
        mn = max(mn, l[i]);
    }
    // cout << mx << " " << mn << endl;
    cout << max(mx - mn + 1, 0) << endl;
}