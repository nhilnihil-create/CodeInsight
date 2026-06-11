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
            vector<ll> tmp;
            ll s=0;
            for(int i=0;i<l;i++){
                s+=V[i];
                tmp.push_back(V[i]);
            }
            for(int i=0;i<r;i++){
                s+=V[N-i-1];
                tmp.push_back(V[N-i-1]);
            }
            sort(tmp.begin(),tmp.end());
            for(int i=0;i<min(K-(l+r),(int)tmp.size());i++){
                if(tmp[i]<0){
                    s-=tmp[i];
                }
            }
            ans = max(ans,s);
        }
    }
    cout << ans << endl;
    return 0;
}