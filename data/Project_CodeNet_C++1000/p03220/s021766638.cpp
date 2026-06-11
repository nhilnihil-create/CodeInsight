#include <bits/stdc++.h>
using namespace std;


#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define int long long int
#define ll long long
#define ld long double

bool isPrime(ll n){if(n<2)return false;for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}

ll lcm(ll x,ll y){
    return (x*y)/(__gcd(x,y));
}

ll nod(ll n){
    while(n%10==0){
        n/=10;
    }
    return n;
}


signed main(){
    fast_IO;
    int t=1;
    //cin>>t;
    while(t--){
        int n,x,a;
        cin>>n>>x>>a;
        int p;
        ld max=10e5,ans=0;
        for(int i=0;i<n;i++){
            cin>>p;
            if(max>abs(a-x+p*0.006)){
                max=abs(a-x+p*0.006);
                ans=i+1;
            }
        }
        cout<<ans<<endl;
        
    }
    return 0;
}

