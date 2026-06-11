#include <bits/stdc++.h>
using namespace std;
int n,k;
long double ans;
int main() {
    cin>>n>>k;
    for (int i=1; i<=n; i++) {
        if (i<k) {
            int ind=i,cnt=0;
            while (ind<k) {
                ind*=2; cnt++;
            }
            //takes cnt flips of coin of heads to get >=k
            ans+=(1/(((long double)(n))*((long double)(1<<cnt))));
        }
        else ans+=(1/((long double)(n)));
    }
    cout<<fixed<<setprecision(12)<<ans<<'\n';
}