#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define MOD 1000000007
typedef long long ll;
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    ll ans = 0;
    for(ll b=k+1;b<=n;b++){
        if(k == 0){
            ans += n;
            continue;
        }
        ll s = n/b;
        ll t = n%b;
        ans += max(b-k, (ll)0)*s + max(t-k+1,(ll)0);
    }
    cout << ans << endl;
    return 0;
}