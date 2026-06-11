#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    ll n, k; cin >> n >> k;

    if(k%2==1){
        ll tmp = n/k;
        cout << (ll)pow(tmp, 3) << endl;
    }
    else{
        ll tmp = n/k;
        ll cnt = 0;
        for(int i=1; i<=n; i++){
            if(i%k==(k/2)) cnt++;
        }

        cout << (ll)(pow(tmp, 3) + pow(cnt, 3)) << endl;
    }

    return 0;
}
