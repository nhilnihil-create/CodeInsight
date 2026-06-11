#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

vector<int> G[MAX_N];
int f[MAX_N];

int main() {
    ll n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i,n)f[i] = -1;

    queue<int> que;
    que.push(0);
    f[0] = 0;

    int flag = 0;
    while(que.size() > 0){
        int x = que.front();
        que.pop();
        rep(i,G[x].size()){
            if(f[G[x][i]] == -1){
                f[G[x][i]] = (f[x] + 1) % 2;
                que.push(G[x][i]);
            }else{
                if(f[G[x][i]] == f[x]){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)break;
    }

    /*
    rep(i,n){
        cout << f[i] << ' ';
    }
    cout << endl;
    */

    ll ans = 0;

    if(flag == 1){
        ans = n * (n - 1) / 2 - m;
    }else{
        ll c[2] = {};
        rep(i,n){
            c[f[i]]++;
        }
        ans = c[0] * c[1] - m;
    }

    cout << ans << endl;
    return 0;
}
 
 
