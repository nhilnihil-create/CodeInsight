#include <bits/stdc++.h>

using ll = long long;

#define mod 1000000007
#define REP(i, n) for (int i = 0; i < n; i++)
#define INF (1 << 29)

using namespace std;

//long C(long n, long r);
//long long gcd(long long a, long long b);
//long long lcm(long long a, long long b);

int n, k;
int x[51], y[51];
void solve()
{
    int n, k;
    cin >> n >> k;
    int x[n], y[n];
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        a[i] = x[i];
        b[i] = y[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = LLONG_MAX;
    for(int h = 0; h < n; h++){
        for(int low = n-1; low >= 0; low--){
            if(b[h] <= b[low]) continue;
            for(int r = n-1; r >= 0; r--){
                for(int l = 0; l < n; l++){
                    if(a[l] >= a[r]) continue;
                    int in = 0;
                    for(int i = 0; i < n; i++){
                        if(a[l] <= x[i] && x[i] <= a[r] && b[low] <= y[i] && y[i] <= b[h]) in++;
                    }
                    if(in >= k) ans = min(ans, (ll)(a[r] - a[l])*(ll)(b[h] - b[low]));
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
