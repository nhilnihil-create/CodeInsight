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
    ll N;
    cin >> N;
    vector<int> A(40, 0);
    for (int i = 0; i < 40; i++) {
        if(N == 0){
            break;
        }
        A[i] = abs(N) % 2;
        if(i % 2 == 0){
            N -= A[i];
        }
        else{
            N += A[i];
        }
        N = N / 2;
    }
    int m = 0;
    for (int i = 0; i < 40; i++) {
        if(A[i] != 0){
            m = i;
        }
    }
    for (int i = m; i >= 0; i--) {
        printf("%d", A[i]);
    }
    printf("\n");
}