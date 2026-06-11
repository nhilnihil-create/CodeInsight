
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<int> aa(n);
    vector<int> ab(n);
    rep(i,n) cin >> aa[i];
    rep(i,n) cin >> ab[i];

    int ans=0;
    for(int i=0; i<n; i++){
        int count=0;
        for(int j=0; j<=i; j++){
            count += aa[j];
        }
        for(int k=i; k<n; k++){
            count += ab[k];
        }
        ans = max(ans,count);
    }
    cout << ans << endl;

}