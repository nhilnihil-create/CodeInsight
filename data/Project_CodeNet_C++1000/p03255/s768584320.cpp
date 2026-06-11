#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

int main(){
    long long N, X;
    cin >> N >> X;
    vector<long long> x(N), y(N+1, 0);
    for(long long i=0; i<N; i++)
        cin >> x[i];
    reverse(x.begin(), x.end());

    for(long long i=1; i<=N; i++)
        y[i] = y[i-1] + x[i-1];

    vector<long long> fac(N);
    fac[0] = 5;
    for(long long i=1; i<N; i++)
        fac[i] = 3+2*i;

    long long ans = 1LL<<60;
    for(long long k=1; k<=N; k++){
        long long tmp = (N+k)*X;
        for(long long j=0; j<=N/k; j++){
            long long l = j*k;
            long long r = min(N, (j+1)*k);
            if(l >= r) continue;
            tmp += fac[j] * (y[r] - y[l]);
            if(tmp > 1LL<<60) break;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
