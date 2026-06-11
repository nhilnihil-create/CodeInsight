#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    //Aの中で絶対値が最大のものがA[j]
    int j = -1, M = 0;
    rep(i, N){
        int A;
        cin >> A;
        if(abs(A) >= abs(M)){
            M = A;
            j = i;
        }
    }
    cout << 2*N-1 << endl;
    rep(i, N){
        cout << j+1 << ' ' << i+1 << endl;
    }
    if(M > 0){
        rep2(i, 1, N-1){
            cout << i << ' ' << i+1 << endl;
        }
    }
    else{
        rep3(i, N, 2){
            cout << i << ' ' << i-1 << endl;
        }
    }
}