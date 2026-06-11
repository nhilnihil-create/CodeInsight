#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> p(m),y(m);
    vector<vector<int>> a(n);
    rep(i,m) {
        cin>>p[i]>>y[i];
        p[i]--;
    }
    rep(i,m) {
        a[p[i]].push_back(y[i]);
    }
    rep(i,n) {
        sort(a[i].begin(),a[i].end());
    }
    rep(i,m) {
        int temp=p[i];
        printf("%06d",temp+1);
        int id=lower_bound(a[temp].begin(),a[temp].end(),y[i])-a[temp].begin();
        printf("%06d\n",id+1);
    }
}
