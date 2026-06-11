#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    vector<vector<pair<int, ll> > > v(n);
    pair<int, int> p[n];
    ll w[n];
    int ans[n];
    for(int i = 0; i < n - 1; i++){
        cin >> p[i].first >> p[i].second >> w[i];
        p[i].first--;
        p[i].second--;
        v[p[i].first].push_back(make_pair(p[i].second, w[i]));
        v[p[i].second].push_back(make_pair(p[i].first, w[i]));
        ans[i] = -1;
    }
    ans[n - 1] = -1;

    queue<int> q;
    q.push(0);
    ans[0] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < v[now].size(); i++){
            if(ans[v[now][i].first] == -1){
                if(v[now][i].second % 2 == 0){
                    ans[v[now][i].first] = ans[now];
                }else{
                    if(ans[now] == 0){
                        ans[v[now][i].first] = 1;
                    }else{
                        ans[v[now][i].first] = 0;
                    }
                }
                q.push(v[now][i].first);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}