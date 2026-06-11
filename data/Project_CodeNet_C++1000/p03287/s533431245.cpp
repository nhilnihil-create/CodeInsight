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
#define mod 1000000007
typedef long long ll;
using namespace std;

ll S[100100]; // S[i] := [1,i]に含まれるお菓子の総数をmで割ったあまり
int main(){
    ll n,m; cin >> n >> m;
    ll A[100100];
    S[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> A[i];
        S[i] = (S[i-1] + A[i]) % m; 
    }
    map<ll,ll> mp;
    ll ans = 0;
    mp[S[0]]++;
    for(int i=1;i<=n;i++){
        //ans += mp[S[i]%m];
        mp[S[i]%m]++;
    }
    /*for(int i=1;i<=n;i++){
        if(A[i] % m == 0) ans++;
    }*/
    for(auto itr = mp.begin();itr != mp.end();itr++){
        ans += itr->second * (itr->second - 1) / 2;
    }
    // ans += mp[0];
    cout << ans << endl;
    return 0;
}