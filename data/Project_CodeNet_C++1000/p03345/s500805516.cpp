#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)

int plu(ll n){
    if(n<0)return (-1)*n;
    else return n;
}
int main(){

    long long a,b,c;
    unsigned long long k;
    cin>>a>>b>>c>>k;
    if(a==b){
        cout<<0<<endl;
        return 0;
    }
    rep(i,k){
        long long INF=1000000000000000000;
        ll aa,bb,cc;
        aa=b+c;
        bb=a+c;
        cc=a+b;
        a=aa;
        b=bb;
        c=cc;
        if(plu(a-b)>INF){
            cout<<"Unfair\n";
            return 0;
        }
    }
    cout<<a-b<<endl;
}
