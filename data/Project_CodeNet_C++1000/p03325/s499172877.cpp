#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long

int main(void)
{
    ll n, cnt = 0;
    cin >> n;

    rep(i,n){
        ll a;
        cin >> a;
        while(a%2 == 0){
            a /= 2;
            cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}