#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MX=30000;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,sum=0;cin>>n;
    if(n==3)return cout<<"2 5 63" , 0;
    vector<ll> a;
    for(ll i=1;i<=MX;i++){
        if(i%2==0 || i%3==0){
            a.push_back(i);
            sum+=i;
            if( (ll)a.size() == n)break;
        }
    }

    ll req = (6 - sum%6)%6;
    for(ll i=n-1;i>=0;i--){
        if( a[i]+req<=MX && ( (a[i]+req)%2==0 || (a[i]+req)%3==0) ){
            a[i]+=req;
            break;
        }
    }

    for(ll i=0;i<n;i++)cout<<a[i]<<" ";

}


