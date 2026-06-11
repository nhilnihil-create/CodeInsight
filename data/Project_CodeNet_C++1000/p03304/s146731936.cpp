#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n, m, d;

    cin >> n >> m >> d;

    if(d == 0){
        printf("%.10Lf", (m - 1) * 1 / ld(n));
    }else{
        printf("%.10Lf", (m - 1) * 2 * (n - d) / ld(pow(n, 2)));
    }
}
