#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n,a,b,c,d,e;
    cin >> n >> a >> b >> c >> d >> e;

    ll minn = min({a,b,c,d,e});

    if(minn == n) put(5);
    else if(n % minn == 0) put(4 + n / minn);
    else put(5 + n / minn);
}