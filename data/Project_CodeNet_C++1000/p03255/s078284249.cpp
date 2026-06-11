#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    unsigned long long n, X, x[200005], sum[200005];
    x[0] = 0;
    sum[0] = 0;
    cin >> n >> X;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
        sum[i] = sum[i - 1] + x[i];
    }
    unsigned long long ans = 18000000000000000000;
    for(ull i = 1; i <= n; i++){
        ull now = X * n + X * i;
        ull number = (n + i - 1) / i;
        for(ull index = 1; index <= number; index++){
            ull mini = n - (i * (index - 1)) - i + 1; 
            ull maxi = n - (i * (index - 1));
            if(mini > n) mini = 1;
            if(mini == 0) mini = 1;
            if(maxi > n) maxi = 0;
            //mini = max(mini, (ull)1);
            //cout << i << " " << index << " " << mini << " " << maxi << endl;
            ull cost = 2 * index + 1;
            if(index == 1) cost = 5;
            now += (sum[maxi] - sum[mini - 1]) * cost; 
        }
        //cout << i << " " << now << endl;
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}
