#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<=ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

int main(void)
{
    ll num, sum;
    cin >> num >> sum;

    REP(i, num) {
        REP(j,num) {
            ll k = num - i - j;
            if ((k >= 0) && (i+j+k == num) && (10000*i + 5000*j + 1000*k == sum)) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;

    return 0;
}
