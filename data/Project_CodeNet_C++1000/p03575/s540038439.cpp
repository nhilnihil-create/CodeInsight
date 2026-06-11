#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n,m;
    cin >> n >> m;
    vector<int> a(m),b(m);
    rep(i,m) cin >> a[i] >> b[i];
    vector<vector<int>> v(n+1);
    rep(i,m){
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    queue<int> que;
    vector<bool> t(n+1);

    int sum=0;
    int x;
    rep(i,m){
        que.push(1);
        while(!que.empty()){
            x=que.front();
            que.pop();
            t[x]=true;
            rep(j,v[x].size()){
                if(x==a[i] && v[x][j]==b[i]) continue;
                if(x==b[i] && v[x][j]==a[i]) continue;
                if(t[v[x][j]]) continue;
                que.push(v[x][j]);
            }
        }

        bool ans=false;
        rep2(i,1,n+1){
            if(!t[i]) ans=true;
            t[i]=false;
        }
        // cout << endl;
        if(ans) sum++;
    }

    cout << sum << endl;

    return 0;
}