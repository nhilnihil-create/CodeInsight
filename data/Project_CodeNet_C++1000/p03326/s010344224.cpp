#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    vector<long long> x(n), y(n), z(n);

    for(long long i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];

    bool plus[3];
    vector<long long> sum;

    long long ans = 0;
    for(long long bit = 0; bit < (1 << 3); bit++){
        for(long long mask = 0; mask < 3; mask++){
            if(bit & (1 << mask)) plus[mask] = true;
            else plus[mask] = false;
        }

        sum.assign(n, 0);
        for(long long i = 0; i < n; i++){
            if(plus[0] == true) sum[i] += x[i];
            else sum[i] -= x[i];

            if(plus[1] == true) sum[i] += y[i];
            else sum[i] -= y[i];

            if(plus[2] == true) sum[i] += z[i];
            else sum[i] -= z[i];
        }

        sort(sum.begin(), sum.end(), greater<long long>());

        long long cnt = 0;
        for(long long i = 0; i < m; i++) cnt += sum[i];

        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}