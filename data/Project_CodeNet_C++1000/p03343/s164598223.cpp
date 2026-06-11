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

int main() {
    int n,k,q;
    cin >> n >> k >> q;
    int a[n];
    rep(i,n)cin >> a[i];
    int ans = 1001001001;
    int f[n] = {};

    rep(loop,n){
        vector<int> v;
        int i = 0;
        while(i<n){
            priority_queue<int> que;
            while(i<n){
                if(f[i] == 0){
                    que.push(-a[i]);
                    i++;
                }else{
                    i++;
                    break;
                }
            }
            while(que.size() >= k){
                v.push_back(-que.top());
                que.pop();
            }
        }
        if(v.size() >= q){
            sort(v.begin(), v.end());
            ans = min(ans, v[q-1] - v[0]);
        }
        int mi = 1001001001;
        int arg = 0;
        rep(j,n){
            if(f[j] == 0 && a[j] < mi){
                mi = a[j];
                arg = j;
            }
        }
        f[arg] = 1;
        
    }

    cout << ans << endl;
    return 0;
}
 
 
