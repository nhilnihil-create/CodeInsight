#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2005*2005;
bitset<N> mask;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,sum=0;cin>>n;
    mask[0]=1;
    for(ll i=0,x;i<n;i++)cin>>x,sum+=x,mask|=mask<<x;

    ll req = (sum+1)/2;
    while(!mask[req])req++;
    cout<<req;
}