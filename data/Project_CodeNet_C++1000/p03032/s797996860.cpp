#include <bits/stdc++.h>
#define all(in) in.begin(),in.end()
using ll = long;
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> v(n); for(int i=0; i<n; i++) cin >> v[i];

    int res = 0;

    for(int ii=0; ii<=n; ii++) for(int jj=0; jj<=n; jj++){
        if(ii+jj > k) continue;
      	if(ii+jj > n) continue;
        int nk = k-ii-jj;
        vector<int> pp(0);
        int ans = 0;
        for(int i=0; i<ii; i++) { pp.push_back(v[i]); ans += v[i]; }
        for(int i=0; i<jj; i++) { pp.push_back(v[n-1-i]); ans += v[n-1-i]; }
        sort(all(pp));
        for(int i=0; i<min(nk,ii+jj); i++) {if(pp[i] >= 0) break; ans -= pp[i]; }
        res = max(res,ans);
    }

    cout << res << endl;
}