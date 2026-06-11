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
    ll N;
    cin >> N;
    for (ll h = 1; h <= 3500; h++) {
        for (ll n = 1; n <= 3500; n++) {
            if((4 * h * n - n * N - h * N) >= 1 && (N*h*n) % (4 * h * n - n * N - h * N) == 0){
                printf("%lld %lld %lld\n", h, n, (N*h*n) / (4 * h * n - n * N - h * N));
                return 0;
            }
        }
    }
}