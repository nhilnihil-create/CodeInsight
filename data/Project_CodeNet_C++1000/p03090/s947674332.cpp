#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, ans=0, tmp=0;
vector<ll> A;

signed main(){
    cin >> N;
    if(N%2==0) {
        cout << N*(N-1)/2-N/2 << endl;
        for(int i=1;i<=N-1;i++) {
            for(int j=i+1;j<=N;j++) {
                if(i+j!=N+1) cout << i << " " << j << endl;
            }
        }
    }
    if(N%2==1) {
        cout << N*(N-1)/2-(N-1)/2 << endl;
        for(int i=1;i<=N-1;i++) {
            for(int j=i+1;j<=N;j++) {
                if(i+j!=N) cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}