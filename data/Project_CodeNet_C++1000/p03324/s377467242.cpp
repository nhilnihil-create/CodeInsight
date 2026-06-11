#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow(ll d){
ll k= 1;
for(int i=0;i<d;i++)k*=100;
return k;
}

int main() {
    ll d;ll n;
    cin>>d>>n;
    ll k = pow(d);
    if(n==100)cout<<k*101;
    else cout<<k*n;


 return 0;
}
