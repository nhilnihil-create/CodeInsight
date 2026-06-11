#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> c(n);
    rep(i,n) cin >> v[i];
    rep(i,n) cin >> c[i];

    int ans = 0;
    for(int bit = 0; bit < (1<<n); bit++){
        int x = 0;
        int y = 0;
        rep(i,n){
            if(bit&(1<<i)){
                x+=v[i];
                y+=c[i];
            }
        }
        ans = max(ans,x-y);
    }

    cout << ans << endl;
    return 0;
}