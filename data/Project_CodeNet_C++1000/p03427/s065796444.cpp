#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,res,sum=0;
    cin>>n;
    res = n;
    ll k = log10(n);
    while(n>0) {
        sum += n%10;
        n /= 10;
    }
    ll l = pow(10,k);
    ll c = res/l;
    if(sum == c+9*k) cout<<c+9*k;
    else cout<<c+9*k-1;
}