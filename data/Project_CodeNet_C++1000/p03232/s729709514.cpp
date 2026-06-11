#include<bits/stdc++.h>

using namespace std;
#define int long long
/*                      */    //#undef int
#define INF 1000000009ll
#define INFL 1000000000000000018ll
#define mod 1000000007
#define pb push_back
#define fi first
#define se second
#define mk make_pair
typedef pair<int, int> PA;
typedef priority_queue<int> PQ;
typedef priority_queue<pair<int, PA> , vector<pair<int, PA> >, greater<pair<int, PA> > >PQG;

int N, A[100005], sum[100005], fact[100005], ans;

int modpow(int a, int p, int MOD)
{
    if(p == 0){
        return 1;
    }
    if(a == 1){
        return a;
    }
    if(p % 2 == 1){
        return a * modpow(a, p - 1, MOD) % MOD;
    }
    else{
        int A = modpow(a, p / 2, MOD);
        return A * A % MOD;
    }
}


signed main()
{
    cin >> N;
    fact[0] = 1;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum[i + 1] = modpow(i + 1, mod - 2, mod);
    }
    for(int i = 1; i <= N; i++){
        sum[i] += sum[i - 1];
        sum[i] %= mod;
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int factN = fact[N];
    for(int i = 0; i < N; i++){
        ans = ((factN * A[i] % mod) * ((sum[i + 1] + sum[N - i] - 1) % mod) + ans) % mod;
    }
    cout << ans % mod << endl;

    return 0;
}
/*



*/
