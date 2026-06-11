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

int main(){
    int N;
    cin >> N;
    int a, b, tmp;
    int ans = inINF;
    for (int i = 1; i < N; i++) {
        a = i;
        b = N - i;
        tmp = 0;
        while(b > 0){
            tmp = tmp + b % 10;
            b = b / 10;
        }

        while(a > 0){
            tmp = tmp + a % 10;
            a = a / 10;
        }
        ans = min(ans, tmp);
    }
    printf("%d\n", ans);
}
