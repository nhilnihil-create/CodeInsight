#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define rep3(i, n) for(int i = n-1; i >= 0; i--)
#define rep4(i, x, n) for(int i = x; i > n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

int main(){
    int N, M;
    cin >> N;
    if(N%2 == 0){
        M = (N-2)*N/2;
        cout << M << endl;
        rep2(i, 1, N+1){
            rep2(j, i+1, N+1){
                if(i+j != N+1){
                    cout << i << ' ' << j << endl;
                }
            }
        }
    }
    else{
        M = (N-3)*(N-1)/2 + N-1;
        cout << M << endl;
        rep2(i, 1, N){
            rep2(j, i+1, N+1){
                if(i+j != N){
                    cout << i << ' ' << j << endl;
                }
            }
        }
    }
}