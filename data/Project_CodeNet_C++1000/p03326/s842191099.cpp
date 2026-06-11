#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF = (1e18) +1;

int main() {
    ll N,M;
    cin >> N >>M;
    vector<ll> x(N),y(N),z(N);
    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    ll ans = -INF;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k =0;k<2;k++){
                vector<ll> sum(N,0);
                for(int l=0;l<N;l++){
                    if(i){
                        sum[l] += x[l];
                    }else{
                        sum[l] -= x[l];
                    }
                    if(j){
                        sum[l] += y[l]; 
                    }else{
                        sum[l] -= y[l];
                    }
                    if(k){
                        sum[l] += z[l];
                    }else{
                        sum[l] -= z[l];
                    }
                }
                sort(sum.rbegin(),sum.rend());
                ll temp =0;
                for(int l=0;l<M;l++){
                    temp += sum[l];
                }
                ans = max(ans,temp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}