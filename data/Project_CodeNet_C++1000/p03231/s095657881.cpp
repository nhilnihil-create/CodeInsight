#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
int main(void){
    ll n,m;
    string a,b;
    cin>>n>>m>>a>>b;
    
    
    ll t=gcd(n,m);
    if(n==m){
        cout<<(a==b?n:-1);
        return 0;
    }else if(t==1){
        cout<<(b[0]==a[0]?n*m:-1);
        return 0;
    }
    for(ll i=0;i<t;++i){
        //cout<<m/t*i<<" "<<n/t*i<<endl;
        if(m/t*i>=m||n/t*i>=n){
            //cout<<"no";
        }else if(b[m/t*i]!=a[n/t*i]){
            cout<<-1;
            return 0;
        }
    }
    cout<<n/t*m;
    
    return 0;
}
