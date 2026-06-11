#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001

int main() {
    int n,m;cin >> n >> m;
    vector<vector<tuple<int,int,int>>> a(n);
    for(int i = 0; i < m; i++) {
        int p,y;cin >> p >> y;
        p--;
        a[p].push_back(tuple<int,int,int>(y,i,0));
    }
    vector<tuple<int,int,int>> b;
    for(int i = 0; i < n; i++) {
        sort(a[i].begin(),a[i].end());
        for(int j = 0; j < a[i].size(); j++) {
            get<2>(a[i][j])=j+1;
            int e=get<1>(a[i][j]);
            get<0>(a[i][j])=e;get<1>(a[i][j])=i+1;
            b.push_back(a[i][j]);
        }
    }

    sort(b.begin(),b.end());
    for(int i = 0; i < m; i++) {
        int s=get<1>(b[i]),t=get<2>(b[i]);
        string g=to_string(s),h=to_string(t);
        for(int j = 0; j < 6-g.size(); j++) {
            cout << 0;
        }
        cout << s;
        for(int j = 0; j < 6-h.size(); j++) {
            cout << 0;
        }
        cout << t << endl;
    }

    return 0;
}