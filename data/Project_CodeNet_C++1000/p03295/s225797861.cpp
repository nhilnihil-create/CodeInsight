#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

using pll = pair<long long, long long>;

int main() {
    int n,m; cin >> n >> m;
    vector<pair<int,int>> r(m);
    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b; a--; b--;
        r[i] = {a,b};
    }

    sort(r.begin(),r.end(),[](pair<int,int> a,pair<int,int> b){return a.second < b.second;});

    int res = 0;
    int cur = -1;
    for(int i=0; i<m; i++){
        if(cur > r[i].first) continue;
        res++;
        cur = r[i].second;
    }
    cout << res << endl;
}