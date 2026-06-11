#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<lli, int> pii;



int main()
{
    lli n, k;
    cin >> n >> k;
    lli a[n];
    for(auto &x: a) cin >> x;
    int cnt1[45] = {0}, cnt0[45] ={0};
    for(auto x: a){
        for(int i=0; i<45; i++){
            if(x%2){
                cnt1[i]++;
            }
            else{
                cnt0[i]++;
            }
            x/=2;
        }
    }
    lli xo = 0LL;
    for(int i=44; i>=0; i--){
        lli tm = 1LL<<i;
        if(xo+tm <= k){
            if(cnt1[i] < cnt0[i]){
                xo += tm;
            }
        }
    }
    lli ans = 0;
    for(auto x: a){
        ans += (x^xo);
    }
    cout << ans << "\n";

    return 0;
}
