#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    string S;
    cin >> S;
    ll N = S.length();
    if(S[0] == '0'){
        printf("-1\n");
        return 0;
    }
    if(S[N-1] == '1'){
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < N-1; i++) {
        if(S[i] != S[N-2-i]){
            printf("-1\n");
            return 0;
        }
    }

    ll t = 0;
    ll u;
    for (int i = 0; i < (N+1)/2; i++) {
        if(S[i] == '1'){
            t = i;
        }
    }

    printf("1 2\n");
    u = 2;
    ll tmp = 1;
    t--;
    while(t >= 0){
        if(S[t] == '0'){
            tmp++;
            t--;
        }
        else{
            for (int i = 0; i < tmp; i++) {
                printf("%lld %lld\n", u, u+i+1);
            }
            u = u + tmp;
            tmp = 1;
            t--;
        }
    }
    for (ll i = u+1; i <= N; i++) {
        printf("1 %lld\n", i);
    }





}