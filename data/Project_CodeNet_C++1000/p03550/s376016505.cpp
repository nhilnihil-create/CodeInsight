#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, Z, W, ans=0, tmp=0;
vector<ll> A;

signed main(){
    cin >> N >> Z >> W;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    if(N==1) cout << abs(A.back()-W) << endl;
    else cout << max(abs(A.back()-W), abs(A.back()-A[A.size()-2])) << endl;
    return 0;
}