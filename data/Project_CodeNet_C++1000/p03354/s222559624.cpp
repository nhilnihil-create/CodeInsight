#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define lint long long

bool seen[100005];

int main(){
    int n, m; cin >> n >> m;
    int p[n], num[n];
    rep(i, n){
        int x; cin >> x; x--;
        p[i] = x;
        num[x] = i;
    }

    vector<int> to[100005];
    rep(i, m){
        int x, y; cin >> x >> y;
        x--; y--;
        to[x].push_back(y);
        to[y].push_back(x);
    }

    int res = 0;
    rep(i, n){
        if(seen[i]) continue;
        set<int> con;

        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int x = q.front(); q.pop();
            seen[x] = true;
            con.insert(x);
            for(int& y : to[x]){
                if(!seen[y]) q.push(y);
            }
        }

        auto itr = con.begin();
        while(itr != con.end()){
            int x = *itr;
            if(con.find(num[x]) != con.end()) res++;
            itr++;
        }
    }
    cout << res << endl;
}