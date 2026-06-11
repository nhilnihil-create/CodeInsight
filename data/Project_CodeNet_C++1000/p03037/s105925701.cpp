#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(void)
{
    int n, m, l=1, r;
    cin >> n >> m;
  	r = n;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        l = max(l, a);
        r = min(r, b);
    }
    cout << max(0, r-l+1) << endl;
    return 0;
}