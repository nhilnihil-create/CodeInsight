#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    int A[N], sum = 0;
    rep(i, N){
        cin >> A[i];
        sum += A[i];
    }
    bitset<2000*2000+1> bs;
    bs.set(0);
    rep(i, N){
        bs |= bs << A[i];
    }
    int i = (sum+1)/2;
    while(true){
        if(bs[i]){
            cout << i << endl;
            break;
        }
        else i++;
    }
}