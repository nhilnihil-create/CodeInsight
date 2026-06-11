#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////
#define MOD (ll)(1e9+7)
ll N;
char s[101010];
ll mk[100];
ll i,j, an;
ll ans;
int main(){
    scanf("%lld%s", &N, s);
    fornum(i,0,N){
        mk[s[i] - 'a']++;
        //printf("%lld,%lld\n", i, ans);
    }
    ans = 1;
    fornum(i,0,30){
        (ans *= mk[i] + 1) %= MOD;
    }
    (ans += MOD - 1) %= MOD;
    printf("%lld", ans);

    return 0;
}