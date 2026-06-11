#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;

int main(){
    ll a[10],flag=0;
    
    rep(i,9){
        cin>>a[i];
    }
    if(a[0]-a[3]!=a[1]-a[4]) flag=1;
    if(a[0]-a[3]!=a[2]-a[5]) flag=1;
    if(a[6]-a[3]!=a[7]-a[4]) flag=1;
    if(a[6]-a[3]!=a[8]-a[5]) flag=1;
    if(a[0]-a[1]!=a[3]-a[4]) flag=1;
    if(a[0]-a[2]!=a[3]-a[5]) flag=1;
    if(a[6]-a[7]!=a[3]-a[4]) flag=1;
    if(a[6]-a[8]!=a[3]-a[5]) flag=1;

    if(flag==0){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}