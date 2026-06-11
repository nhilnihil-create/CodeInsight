#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n,i;
    cin>>n;
    ll pow[33];
    pow[0]=1;
    for(i=1;i<33;i++){
        pow[i]=pow[i-1]*2;
    }

    ll z[n],w[n];
    int flag=-1;

    for(i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        z[i]=x+y;
        if(flag==-1) flag=(3000000000+z[i])%2;
        else if(flag!=(3000000000+z[i])%2) {
            cout<<-1<<endl;
            return 0;
        }
        w[i]=x-y;
    }

    int add=0;
    if(flag==0) add=1;
    cout<<32+add<<endl;
    if(add){
        cout<<1<<" ";
    }
    cout<<pow[0];
    for(i=1;i<32;i++){
        cout<<" "<<pow[i];
    }
    cout<<endl;

    if(add){
        for(i=0;i<n;i++){
            z[i]-=1;
            w[i]-=1;
        }
    }

    for(i=0;i<n;i++){
        if(add) cout<<'R';
        z[i]=z[i]+pow[32]-1;
        w[i]=w[i]+pow[32]-1;
        z[i]/=2;
        w[i]/=2;
        bool zz,ww;
        for(int j=0;j<32;j++){
            zz=z[i]&1;
            ww=w[i]&1;
            if(zz&ww) cout<<'R';
            if(!zz&ww) cout<<'D';
            if(zz&!ww) cout<<'U';
            if(!zz&!ww) cout<<'L';
            z[i]=z[i]/2;
            w[i]=w[i]/2;
        }
        cout<<endl;
    }
    return 0;
}
