#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define ve vector
#define pq priority_queue
#define vi vector<int>
#define vl vector<long long>
#define vii vector<vector<int>>
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1000000007;



int main()
{
    int n,k;
    cin >> n >> k;
    
    vector<pair<ll,int>> a(n);
    rep(i,n){
        cin >> a[i].se >> a[i].fi;
        a[i].se--;
    }
    
    sort(all(a));
    reverse(all(a));
    
    ll ans = 0;
    
    vector<int> f(n,0);

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> used;
    priority_queue<pair<ll,int>> next;

    ll now_ans = 0;
    ll now_num = 0;
    rep(i,k){
        if(f[a[i].se] == 0) now_num++;
        f[a[i].se]++;
        used.push(a[i]);
        now_ans += a[i].fi;
        ans = now_ans + now_num*now_num;
    }
    for (int i = k; i < n; i++) {
        if(f[a[i].se] == 0) {
            next.push(a[i]);
            f[a[i].se]++;
        }
    }
    
    while (!used.empty() && !next.empty()) {
        if(f[used.top().se] > 1){
            f[used.top().se]--;
            now_ans-=used.top().fi;
            now_ans += next.top().fi;
            now_num++;
            ans = max(ans,now_ans + now_num*now_num);
            next.pop();
        }
        
        used.pop();
    }

    out(ans);


    return 0;
}
