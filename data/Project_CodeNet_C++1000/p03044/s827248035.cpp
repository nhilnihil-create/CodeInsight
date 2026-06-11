#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> tr(n+1);
    rep(i,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        tr.at(a).push_back({b, c});
        tr.at(b).push_back({a, c});
    }
    vector<int> cols(n+1);
    vector<int> visited(n+1);
    queue<int> q;
    cols.at(1) = 0;
    visited.at(1) = true;
    q.push(1);
    while(q.size()){
        auto x = q.front(); q.pop();
        for(auto p : tr.at(x)){
            if(visited.at(p.first)) continue;
            if(p.second % 2 == 0) cols.at(p.first) = cols.at(x);
            else cols.at(p.first) = (cols.at(x)+1) % 2;
            visited.at(p.first) = true;
            q.push(p.first);
        }
    }
    rep(i,n){
        cout << cols.at(i+1) << endl;
    }
    return 0;
}