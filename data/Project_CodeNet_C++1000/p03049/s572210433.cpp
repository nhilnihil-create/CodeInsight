#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    ll n;
    cin>>n;
    ll ans=0,x=0,y=0,z=0;
    rep(i,n){
        string s;
        cin>>s;
        rep(i,s.size()){
            if(s[i]=='A' && s[i+1]=='B') ans++;
        }

        if(s[0]=='B' && s.back()=='A') x++;
        else if(s[0]=='B') y++;
        else if(s.back()=='A') z++;
    }

    if(y==0 && z==0){
        ans+=max(x-1,0LL);
    }
    else if(y==z){
        ans+=x+y;
    }
    else if(y>z){
        ans+=x+min(y,z);
    }
    else if(y<z) ans+=x+min(y,z);

    cout<<ans<<endl;
}
