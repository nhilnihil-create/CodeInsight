#include <bits/stdc++.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll BIG=1e15;

ll N;
int query(ll x){
    cout<<x<<endl;
    string S; cin>>S;
    if(S=="Vacant") exit(1);
    if(S=="Male") return 1;
    if(S=="Female") return -1;
    return 0;
}

void saiki(ll L, ll R, int l, int r){
    ll MID=(L+R)/2;
    int t=query(MID);
    if(l==t && (MID-L)%2==1) saiki(L,MID,l,t);
    else if (l!=t && (MID-L)%2==0) saiki(L,MID,l,t);
    else saiki(MID,R,t,r);
    return;
}


int main(){
    cin>>N;
    ll n=N/2;
    int a=query(0);
    int b=query(n);
    if(a==b && n%2==1) saiki(0,n,a,b);
    else if(a!=b && n%2==0) saiki(0,n,a,b);
    else saiki(n,N,b,a);
}