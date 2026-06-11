#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pw(ll a,ll b){
    if(b==0) return 1;
    if(b%2==1) return pw(a,b-1)*a;
    ll temp=pw(a,b/2);
    return temp*temp;
}

ll kosuu(ll n,ll k){
    if(k%2==1) return 0;
    ll count=0;
    for(int i=1;i<=n;i++){
        if(i%k==k/2) count++;
    }
    return count;
}

ll kumi(ll n, ll k){
    return pw(n/k,3)+pw(kosuu(n,k),3);
}
int main(void){
    ll n,k;
    cin>>n>>k;
    cout<<kumi(n,k)<<endl;
}