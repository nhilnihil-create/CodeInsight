#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll xorf(ll x){
    if(x%4==0)
        return x;
    else if(x%4==1)
        return 1;
    else if(x%4==2)
        return x+1;
    return 0;
}

int main(){

    ll l,r;
    cin>>l>>r;
    cout<<(xorf(max(0ll,l-1))^xorf(r));


return 0;
}
