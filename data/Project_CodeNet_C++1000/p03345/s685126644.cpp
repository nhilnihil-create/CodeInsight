#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    ll a,b,c,k;cin>>a>>b>>c>>k;
    if(abs(b-a)>=1e18){co("Unfair");return 0;}
    co((k%2==1)?b-a:a-b);
}