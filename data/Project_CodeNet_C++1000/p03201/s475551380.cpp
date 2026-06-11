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

int main(){
    int N;
    cin >> N;
    ll a;
    map<ll, int> A;
    for (ll i = 0; i < N; i++) {
        cin >> a;
        if(A.count(-a)){
            A[-a]++;
        }
        else{
            A[-a] = 1;
        }
    }
    int ans = 0;
    int tmp;
    for (auto v : A){
        ll w = v.first;
        for (int k = 30; k >= 1; k--) {
            if(A.count(-(w + (1<<k)))){
                if(-(w + (1<<k)) == w){
                    tmp = A[w] / 2;
                    ans += tmp;
                    A[w] -= tmp * 2;
                    continue;
                }
                tmp = min(A[-(w + (1<<k))], A[w]);
                ans += tmp;
                A[-(w + (1<<k))] -= tmp;
                A[w] -= tmp;
            }
        }
    }
    printf("%d\n", ans);


}