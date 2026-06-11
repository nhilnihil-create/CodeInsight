#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll a) {
    if (a%2)
        return (a+1)/2%2;
    return a/2%2^a;
}

int main() {
    ll a,b;cin>>a>>b;
    cout<<(f(a-1)^f(b))<<endl;
    return 0;
}