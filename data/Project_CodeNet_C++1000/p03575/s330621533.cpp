#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int N, M;
vector<int> a(55), b(55);
vector<vector<bool>> G(55, vector<bool>(55, false));
vector<bool> visited(55, false);
queue<int> que;

int main(){
    cin >> N >> M;
    rep(i, M){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        G[a[i]][b[i]] = G[b[i]][a[i]] = true;
    }

    int ans = 0;

    rep(i, M){
        G[a[i]][b[i]] = G[b[i]][a[i]] = false;
        rep(j, N) visited[j] = false;
        
        visited[0] = 0;
        que.push(0);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            visited[v] = true;

            rep(j, N){
                if( visited[j] || !G[v][j]) continue;
                que.push(j);
            }
        }

        bool flag = false;
        rep(j, N){
            if(!visited[j]){
                flag = true;
                break;
            }
        }
        if(flag) ans++;

        G[a[i]][b[i]] = G[b[i]][a[i]] = true;
    }

    cout << ans << endl;
}