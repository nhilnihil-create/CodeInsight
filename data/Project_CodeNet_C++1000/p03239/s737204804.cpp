#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n,t;
    cin >> n >> t;
    vector<int> c(n),u(n);
    for(int i=0;i<n;i++){
        cin >> c[i] >> u[i];
    }
    int ans = 1001;
    for(int i=0;i<n;i++){
        if(u[i]<=t){
            ans = min(ans,c[i]);
        }
    }

    if(ans == 1001) cout << "TLE" << endl;
    else cout << ans << endl;

}