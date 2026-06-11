#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N, M;
    string S;
    cin >> N >> M >> S;
    set<int> s[N][2];
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(S[a] == 'A') s[b][0].insert(a);
        else s[b][1].insert(a);
        if(S[b] == 'A') s[a][0].insert(b);
        else s[a][1].insert(b);
    }
    int cnt = 0;
    queue<int> que;
    bool able[N];
    fill_n(able, N, true);
    rep(i, N){
        if(s[i][0].size()*s[i][1].size() == 0){
            cnt++;
            able[i] = false;
            que.push(i);
        }
    }
    while(!que.empty()){
        int p = que.front();
        que.pop();
        rep(i, 2){
            set<int>::iterator ite = s[p][i].begin();;
            rep(j, s[p][i].size()){
                int q = *ite;
                if(S[p] == 'A') s[q][0].erase(p);
                else s[q][1].erase(p);
                if(able[q] && s[q][0].size()*s[q][1].size() == 0){
                    cnt++;
                    able[q] = false;
                    que.push(q);
                }
                ite++;
            }
        }
    }
    if(cnt == N) cout << "No" << endl;
    else cout << "Yes" << endl;
}