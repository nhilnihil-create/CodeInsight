#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll n;cin>>n;
    ll p,q[200010];
    rep(i,0,n){
        cin>>p;
        p--;
        q[p]=i;
    }
    ll CN=0,cn=1;
    rep(i,0,n-1){
        if(q[i]<q[i+1])cn++;
        else {
            CN=max(CN,cn);
            cn=1;
        }
    }
    CN=max(CN,cn);
    cout<<n-CN<<endl;
    

}





