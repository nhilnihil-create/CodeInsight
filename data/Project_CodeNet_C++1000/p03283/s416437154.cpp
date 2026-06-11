#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    int n, m, q;
    cin>>n>>m>>q;
    vector<pair<int, int> > v(m);
    vector<pair<int, int> > p(q);
    rep(i, m) {
        int a, b;
        cin>>a>>b;
        --a;--b;
        v[i]=make_pair(a, b);
    }
    sort(v.begin(), v.end());
    vector<int>left(m);
    vector<vector<int> > right(n, vector<int>(n));
    rep(i, m){
        left[i] = v[i].first;
        right[v[i].first][v[i].second]++;
    }
    vector<vector<int> > rightsum(n, vector<int>(n));
    rep(i, n){
        rightsum[i][0] = right[i][0];
        rep(j, n-1){
            rightsum[i][j+1] = rightsum[i][j] + right[i][j+1];
        }
    }
    rep(i, q){
        int a, b;
        cin>>a>>b;
        --a;--b;
        p[i]=make_pair(a, b);
    }
    rep(i, q){
        int a = p[i].first;
        int b = p[i].second;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i<a) continue;
            ans += rightsum[i][b];
        }
        cout<<ans<<endl;
    }
    return 0;
}