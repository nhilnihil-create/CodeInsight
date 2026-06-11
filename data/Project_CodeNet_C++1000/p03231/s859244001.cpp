#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, M, C, a, b, f, g, h;
    cin >> N >> M;
    string s, t;
    cin >> s >> t;
    C = N * M / __gcd(N, M);
    a = C / N;
    b = C / M;
    f = a * b / __gcd(a, b);
    g = f / a;
    h = f / b;
    for (int i = 0; i < N; i++) {
        if(i * g >= N || i * h >= M) break;
        if(s[i*g] != t[i*h]){
            printf("-1\n");
            return 0;
        }
    }
    printf("%lld\n", C);

}