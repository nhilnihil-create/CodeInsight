#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 3e3 + 9;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> LL;
priority_queue<ll,vector<ll>,greater<ll>> pq;
ll n,k,a[N],i,j,l;
ll maxx;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>n>>k;
    for (i = 1;i <= n;i++) cin>>a[i];
    for (i = 0;i <= min(n,k);i++){
        for (j = 0;j <= min(n,k) - i;j++){
            if (!i&&!j) continue;
            l = 1;
            while(l <= i) pq.push(a[l]),l++;
            l = n;
            while(l >= n - j + 1) pq.push(a[l]),l--;
            ll p = i + j;
            while(p < k&&!pq.empty()){
                if (pq.top() > 0){

                    break;
                }
                pq.pop(); p++;
            }
            ll cnt = 0;
            while(!pq.empty()) cnt += pq.top(),pq.pop();
            maxx = max(maxx,cnt);

        }
    }
    cout<<maxx;
}

