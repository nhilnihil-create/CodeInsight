// i will show you da wae
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fill(x,v) memset(x,v,sizeof(x))
#define FOR(i,a,b) for(int i = int(a); i < int(b); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define N 100050
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

ll dp[N];

ll solve(int k){
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    FOR(i,0,k) dp[i] = LLONG_MAX;
    FOR(i,1,10){
        pq.push(ii(i,i%k));
        dp[i%k] = i;
    }

    while(1){
        ii top = pq.top();
        pq.pop();
        ll sum = top.first, mod = top.second;
        if(mod == 0) return sum;
        FOR(i,0,10){
            ll nmod = (mod*10+i)%k, nsum = sum + i;
            if(dp[nmod] > nsum){
                dp[nmod] = nsum;
                pq.push(ii(nsum,nmod));
            }
        }
    }
    return 0;
}

int main(){
    
    int k;
    cin >> k;
    cout << solve(k) << endl;

    return 0;
}
