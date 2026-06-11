#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll k,a,b;cin>>k>>a>>b;
    if(b-a<=2)return cout<<k+1 , 0;
    ll ans = min(k , a-1) + 1;
    k-=min(k,a-1);
    ans+=(b-a)*(k/2);
    ans+=k%2;
    cout<<ans;
}