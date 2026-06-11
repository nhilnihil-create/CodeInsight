#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,K;
    cin >> N >> K;
    vector<ll> V(N);
    rep(i,N){
        cin >> V[i];
    }
    ll ans = 0;
    for(int l=0;l<=min(N,K);l++){
        for(int r=0;r<=min(N,K);r++){
            if(l+r>min(N,K))  continue;
            priority_queue<int> pq;
            ll s=0;
            for(int i=0;i<l;i++){
                s+=V[i];
                if(V[i]<0){
                    pq.push(-V[i]);
                }
            }
            for(int i=0;i<r;i++){
                s+=V[N-i-1];
                if(V[N-i-1]<0){
                    pq.push(-V[N-i-1]);
                }
            }
            int cnt=1;
            while(1){
                if(cnt>K-(l+r)||pq.size()<=0) break;
                s += pq.top();
                pq.pop();
                cnt++;
            }
            ans = max(ans,s);
        }
    }
    cout << ans << endl;
    return 0;
}