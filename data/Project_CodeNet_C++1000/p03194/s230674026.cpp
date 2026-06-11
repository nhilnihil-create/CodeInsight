#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ct(n) cout << n << endl;
#define cts(n) cout << n << " ";
#define cte cout << endl;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repo(i,o,n) for(int i=o;i<n;i++)
#define repm(i,n) for(int i=n-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end());
#define vdelete(v) (v).erase(unique(all(v)), (v).end());
#define vcopy(v1,v2) copy((v1).begin(), (v1).end(), back_inserter((v2)));
#define pb(n) push_back(n);

int n,p,ans=1,a=2;

main() {
    cin >> n >> p;
    if(n>=40) {
        ct(ans)
        return 0;
    }
    if (n==1) {
        ct(p)
        return 0;
    }
    while(1) {
        int hoge = pow(a,n);
        if (hoge < 0 || hoge > p) break;
        while (!(p%hoge)) {
            ans *= a;
            p /= hoge;
        }
        if (a==2) a++;
        else a+=2;
    }
    ct(ans)

}
