#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    if(A[0]!=0){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    for(int i=1;i<N;i++){
        if(A[i]==A[i-1])ans += A[i];
        else if(A[i]==A[i-1]+1){
            ans++;
        }else if(A[i]>A[i-1]+1){
            cout << -1 << endl;
            return 0;
        }else{
            ans += A[i];
        }
    }
    cout << ans << endl;
}