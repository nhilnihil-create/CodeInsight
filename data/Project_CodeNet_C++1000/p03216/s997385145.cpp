#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    ll n,q;
    string s;
    cin>>n>>s>>q;
    while(q--){
        ll k;
        cin>>k;
        ll m=0,c=0,cnt=0;
        ll r = 0;
        ll ans = 0;
        for(int i=0;i<k;i++){
            if(s[i]=='M') m++;
            if(s[i]=='C') c += m,cnt++;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='D' && m>0 && c>0) ans += c;
            if(s[i]=='M'){
                c -= cnt;
                m--;
            }
            if(s[i]=='C') cnt--;
            if(i+k<n){
                if(s[i+k]=='M') m++;
                if(s[i+k]=='C') c += m,cnt++;
            }
            //cerr<<i<<" "<<ans<<endl;
        }
        cout << ans << endl;
    }
}