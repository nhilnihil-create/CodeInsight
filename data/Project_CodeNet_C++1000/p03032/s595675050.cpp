#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i, n)cin >> v[i];
    int ans = 0;
    rep(i, k+1){
        priority_queue<int, vector<int>, greater<int>> que;
        if(i >= n){
            rep(j, n)que.push(v[j]);
            int a = 0;
            while(a < (k-i) && !que.empty()){
                if(que.top() > 0)break;
                que.pop();
                a++;
            }
            int now = 0;
            while(!que.empty()){now += que.top(); que.pop();}
            ans = max(ans, now);
        }else{  
            rep(j, i+1){
                rep(a, j)que.push(v[a]);
                rep(a, i-j)que.push(v[n-a-1]);
                int a = 0;
                while(a < (k-i) && !que.empty()){
                    if(que.top() > 0)break;
                    que.pop();
                    a++;
                }
                int now = 0;
                while(!que.empty()){now += que.top(); que.pop();}
                
                ans = max(ans, now);
            }
        }
    }
    cout << ans << endl;
}
