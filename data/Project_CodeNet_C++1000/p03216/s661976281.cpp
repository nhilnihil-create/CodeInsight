#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    string str;cin>>str;
    ll q;cin>>q;
    while(q--){
        ll k;cin>>k;
        ll ans=0,dm=0,d=0,m=0;
        for(ll i=0;i<n;i++){
            if(str[i]=='C')ans+=dm;
            else if(str[i]=='D')d++;
            else if(str[i]=='M')dm+=d,m++;

            if(i<k-1)continue;
            ll pos=i-(k-1);
            if(str[pos]=='D')dm-=m,d--;
            else if(str[pos]=='M')m--;
        }
        cout<<ans<<"\n";
    }
}