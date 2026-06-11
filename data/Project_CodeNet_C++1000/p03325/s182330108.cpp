#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define INF 10000000000000000LL
#define ll  long long 
const int inf =INT_MAX;
const int MAX=3e5+9;
const ll MOD=1e9+7;
const int TOT_PRIMES=1e6+9;
const int MAX_A=71;
const int LN=20;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin>>N;
    vector<ll> a(N);
    for(int i = 0; i < N; ++i){
        cin>>a[i];
    }
    ll ans = 0;
    for(int i = 0; i < N; ++i){
        if(a[i] % 2 == 1)
            continue;
        int res = 0;
        while(res != 1){
            res = a[i] % 2;
            a[i] /= 2;
            if(!res)
                ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}