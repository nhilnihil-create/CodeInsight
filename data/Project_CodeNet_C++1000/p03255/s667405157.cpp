#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,x;

    cin >> n >> x;

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> sum(n+1,0);

    for(int i = 1; i < n+1; i++){
        sum[i] = sum[i-1] + a[i-1];
    }

    if(n == 1){
        cout << a[0]*5 + 2*x << endl;
        return 0;
    }

    ll ans = INF;

    for(int i = n-2; i >= 0; i -= 2){
        ll pn = (n - i)/2;
        ll tmpans = x*(n + pn) + (sum[n] - (i >= 0? sum[i] : 0))*5;
        ll t1 = tmpans;
        ll c = 2;
        for(int j = i; j >= 0; j -= pn){
            t1 += (5+c)*(sum[j] - (j-pn >= 0? sum[j-pn] : 0));
            c += 2;
        }
        if(t1 > 0){
            ans = min(ans,t1); //best result must be positive number
        }
        if(i > 0){
            ll t2 = tmpans + x + a[i-1]*5;
            c = 2;
            for(int j = i-1; j >= 0; j -= pn){
                t2 += (5+c)*(sum[j] - (j-pn >= 0? sum[j-pn] : 0));
                c += 2;
            }
            if(t2 > 0){
               ans = min(ans,t2); //best result must be positive number
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}