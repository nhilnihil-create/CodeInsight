#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 100000000;
ll i,j,k;
ll mod=1000000007;

int main(){
    ll n,answer=0,answer2=0;cin>>n;
    vector<ll> a(n+1),key(n+1);
    
    for(i=1;i<=n;i++){cin>>a[i];}
    for(i=1;i<=n;i++){key[i]=a[i]-i;}

    sort(key.begin()+1,key.end());
    
    double center;
    if(n%2==0){center=(key[n/2]+key[n/2+1])/2;}
    else{center=key[(n+1)/2];}

    ll llcenter=(ll)(center);
    if(center>=0 && abs(double(llcenter)-center)-abs(double(llcenter+1)-center)>=0){
        llcenter=llcenter+1;
    }
    if(center<0 && abs(double(llcenter)-center)-abs(double(llcenter-1)-center)>=0){
        llcenter=llcenter-1;
    }

    for(i=1;i<=n;i++){
        answer+=abs(key[i]-llcenter);
    }
    cout<<answer<<endl;
    return 0;
}