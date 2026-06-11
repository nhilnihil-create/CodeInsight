#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    vector<vector<ll>> A(N,vector<ll>(3,0));
    rep(i,N) {
        ll a,b;
        cin >> a >> b;
        A[i][0] = a+b;
        A[i][1] = a;
        A[i][2] = b;
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    
    ll a,b;
    a = b = 0;

    rep(i,N) {
        if (i%2==0) {
            a += A[i][1];
        }
        else b += A[i][2];
    }
    ll ans = a-b;
    cout << ans << endl;
}
