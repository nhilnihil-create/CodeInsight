#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF 1E18



int main(){
    int a,b,c;
    cin>>a>>b>>c;

    int m = max({a,b,c});
    if(m%2 == (a+b+c)%2) cout << (3*m -(a+b+c))/2 <<endl;
    else cout << (3*(m+1) -(a+b+c))/2 <<endl;

    return 0;
}
