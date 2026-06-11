#include <iostream>

#define N_MAX 200000

using namespace std;

typedef unsigned long long ll;

ll x[N_MAX];
ll sum[N_MAX+1];

ll cost(int n){
    if(n == 1) return 5;
    else return n*2+1;
}

int main(){
    ll N, X;
    cin >> N >> X;
    ll ans = __LONG_LONG_MAX__;
    //if(N > 2000) return 0;
    sum[0] = 0;
    for(int i = 0; i < N ; i++){
        cin >> x[i];
        sum[i+1] = sum[i]+x[i];
    }
    for(ll i = 1; i <= N; i++){
        ll m, k;
        if(N%i == 0){
            m = N/i;
            k = i;
        }else{
            m = N/i+1;
            k = N%i;
        }
        ll tmp = X*i + X*N;
        tmp += (sum[k]-sum[0])*cost(m);
        
        for(ll j = 1; j < m; j++){
            tmp += (sum[k+j*i]-sum[k+(j-1)*i])*cost(m-j);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}