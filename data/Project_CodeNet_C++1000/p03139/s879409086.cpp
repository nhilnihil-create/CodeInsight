#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,a,b;cin>>n>>a>>b;
    ll mx = min(a,b);
    ll mn = max(0ll , a+b - n );
    cout<<mx<<" "<<mn;
}