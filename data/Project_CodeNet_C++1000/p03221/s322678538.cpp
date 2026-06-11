#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    int n, m;
    cin >> n >> m;
    vector< vector<P> > city(n+1);
    for(int i=1; i<=m; i++){
        int p, y;
        cin >> p >> y;
        city[p].push_back(make_pair(y, i));
    }
    for(int j=1; j<=n; j++){
        sort(city[j].begin(), city[j].end());
    }
    vector<P> ans(m+1);
    for(int j=1; j<=n; j++){
        for(int i=1; i<=city[j].size(); i++){
            ans[city[j][i-1].second] = make_pair(j, i);
        }
    }
    for(int i=1; i<=m; i++){
        string left = to_string(ans[i].first);
        while(left.length() < 6){
            left = "0" + left;
        }
        string right = to_string(ans[i].second);
        while(right.length() < 6){
            right = "0" + right;
        }
        cout << left << right << endl;
    }
    return 0;
}