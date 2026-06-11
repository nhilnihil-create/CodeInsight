#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> data(n);
    vector<int> data2(m), data3(m);
    rep(i, m){
        int a, b; cin >> a >> b;
        a--; b--;
        data[a].push_back(b);
        data[b].push_back(a);
        data2[i] = a;
      	data3[i] = b;
    }
    int ans = 0;
    rep(i,m){
        int a = data2[i];
        int b = data3[i];
        data[a].erase(remove(data[a].begin(), data[a].end(), b), data[a].end());
      	data[b].erase(remove(data[b].begin(), data[b].end(), a), data[b].end());
        vector<bool> finder(n,false);
        queue<int> que;
        finder[0] = true;
        que.push(0);
        while(!que.empty()){
            int next = que.front(); que.pop();
            for(auto nn : data[next]){
                if(finder[nn] == false){
                    finder[nn] = true;
                    que.push(nn);
                }
            }
        }
        bool ans2 = true;
        rep(i,n) if(finder[i] == false) ans2 = false;
        if(ans2) ans++;
      	data[a].push_back(b);
      	data[b].push_back(a);
    }
    cout << m-ans << endl;
}