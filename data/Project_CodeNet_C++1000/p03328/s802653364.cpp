#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll a,b;cin>>a>>b;
    ll sum=0,last = b-a;
    for(ll i=1;i<last;i++)sum+=i;
    cout<<max(0ll,sum-a);
}
