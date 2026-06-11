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
    ll N, Z, W;
    cin >> N >> Z >> W;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }   
    if(N == 1){
        printf("%d\n", abs(W - A[0]));
        return 0;
    }
    W -= A[N-1]; W = abs(W);
    A[N-2] -= A[N-1]; A[N-2] = abs(A[N-2]);
        
    if(W > A[N-2]){
        printf("%lld\n", W);
    }
    else{
        printf("%d\n", A[N-2]);
    }

}