#include<bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int n, m;
vector<set<int>> c, p;

int main(){
    cin >> n >> m;
    c.resize(n);
    p.resize(n);
    rep(i, n + m - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        c[a].insert(b);
        p[b].insert(a);
    }
    int s;
    rep(i, n){
        if (p[i].empty()){
            s = i;
            p[i].insert(-1);
            break ;
        }
    }
    queue<int> que;
    que.push(s);
    while (!que.empty()){
        int x = que.front();
        que.pop();
        for (auto nx : c[x]){
            if (p[nx].size() == 1)
                que.push(nx);
            else p[nx].erase(x);
        }
    }
    rep(i, n){
        cout << *p[i].begin() + 1 << endl;
    }
}