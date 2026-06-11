#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    ll a,b;
    cin>>a>>b;
    ll fa,fb;
    
    if(a==0 && b==0){
        cout<<0<<endl;
        return 0;
    }
    if(a==0 || a==1){
        if(b%4==0) fb=b;
        else if(b%4==1) fb=1;
        else if(b%4==2) fb=b+1;
        else fb=0;
        cout<<fb<<endl;
        return 0;
    }
    
    a=a-1;
    if(a%4==0) fa=a;
    else if(a%4==1) fa=1;
    else if(a%4==2) fa=a+1;
    else fa=0;
    if(b%4==0) fb=b;
    else if(b%4==1) fb=1;
    else if(b%4==2) fb=b+1;
    else fb=0;

    //cout<<fb<<" "<<fa<<endl;
    ll ans=fb^fa;
    cout<<ans<<endl;

}

