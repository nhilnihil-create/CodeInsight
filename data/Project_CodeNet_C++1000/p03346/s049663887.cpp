#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    int A[N+1];
    rep2(i, 1, N){
        int P;
        cin >> P;
        A[P] = i;
    }
    int len = 0, i = 1;
    while(i <= N){
        int j = 0;
        while(i+j < N && A[i+j] < A[i+j+1]) j++;
        len = max(len, j+1);
        i += j+1;
    }
    cout << N-len << endl;
}