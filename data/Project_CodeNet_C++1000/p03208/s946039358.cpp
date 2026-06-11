#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    int n,k;
    cin >> n >> k;
    vector <long long> h(n);
    rep(i,n) cin >> h[i];

    sort(all(h));

    long long ans = abs(h[0] - h[k-1]);
    
    for(int i=0; i<=n-k; i++){
        long long des = abs(h[i+k-1] - h[i]);
        if(ans > des){
            ans = des;
        }
    }

    cout << ans << endl;
}
