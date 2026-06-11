#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
#define int long
#define ll long long
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define fi first
#define se second
const int INF = 1e9;
using namespace std;

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int N; cin >> N;
    vi G[N];
    rep(i,N-1){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].eb(b);
        G[b].eb(a);
    }
    int A[N]; 
    rep(i,N) cin >> A[i];
    int vis[N]; 
    rep(i,N) vis[i]=0;
    int sum=0;
    int pos=0;
    sort(A,A+N,greater<int>());
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int a = q.front(); q.pop();
        vis[a]=A[pos];
        if(a!=0)sum+=A[pos];
        pos++;
        for(auto t:G[a]){
            if(vis[t]>0) continue;
            q.push(t);
        }
    }
    cout << sum << endl;
    rep(i,N) {
        cout << vis[i] << " ";
    }
    cout << endl;
}