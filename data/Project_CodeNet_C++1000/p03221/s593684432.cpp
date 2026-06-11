#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int> p(m),y(m);
    vector<int> s[n];
    rep(i,m){
        cin >> p[i] >> y[i];
        p[i]--;
        s[p[i]].push_back(y[i]);
    }
    rep(i,n) sort(s[i].begin(),s[i].end());
    rep(i,m){
        auto it = lower_bound(s[p[i]].begin(),s[p[i]].end(),y[i]);
        int now = distance(s[p[i]].begin(),it);
        printf("%012lld\n",ll(p[i]+1)*1000000+ll(now+1));
    }
    return 0;
}