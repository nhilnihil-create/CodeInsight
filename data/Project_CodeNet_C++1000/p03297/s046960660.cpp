#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string print[]={"No","Yes"};
ll solve(){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    if(b>a)return 0;
    if(b>d)return 0;

    ll g=__gcd(b,d);
    ll mn = a - (a-c-1)/g*g - b;
    return mn>=0;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t;cin>>t;
    while(t--)cout<<print[solve()]<<"\n";
}


