#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

vector<int> memo(100005, -1);

int f(int N){
    if(memo[N] != -1){
        return memo[N];
    }

    int ret = inINF;
    if(N >= 1) ret = min(ret, f(N-1) + 1);
    if(N >= 6) ret = min(ret, f(N-6) + 1);
    if(N >= 36) ret = min(ret, f(N-36) + 1);
    if(N >= 216) ret = min(ret, f(N-216) + 1);
    if(N >= 1296) ret = min(ret, f(N-1296) + 1);
    if(N >= 7776) ret = min(ret, f(N-7776) + 1);
    if(N >= 46656) ret = min(ret, f(N-46656) + 1);
    if(N >= 9) ret = min(ret, f(N-9) + 1);
    if(N >= 81) ret = min(ret, f(N-81) + 1);
    if(N >= 729) ret = min(ret, f(N-729) + 1);
    if(N >= 6561) ret = min(ret, f(N-6561) + 1);
    if(N >= 59049) ret = min(ret, f(N-59049) + 1);
    return memo[N] = ret;
}

int main(){
    int N;
    cin >> N;
    memo[0] = 0;
    printf("%d\n", f(N));
}