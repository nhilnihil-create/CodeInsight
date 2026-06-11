#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll n, ans1=0, ans2=0;
    cin >> n;
    while(n>=10){
        ans1 += n%10;
        ans2 += 9;
        n /= 10;
    }
    ans1 += n;
    ans2 += n-1;
    cout << max(ans1, ans2) << endl;
    return 0;
}