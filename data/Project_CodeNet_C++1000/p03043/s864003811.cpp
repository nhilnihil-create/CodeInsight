#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int nax = 1e7+7;
const int MOD = 1e9+7;

int main(){
    int n, k; cin>>n>>k;

    double ans = 0;

    for(int i=1; i<=n; i++){
        double tmp = k;
        double curr = 1;
        while(tmp>i){
            tmp/=2;
            curr/=2;
        }
        ans += curr;
    }

    ans /= n;

    cout<<setprecision(10)<<ans<<endl;

    return 0;
}