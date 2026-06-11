#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    ll sum=0;
    int minb=INF;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
        if(a[i]>b[i]){
            minb=min(minb,b[i]);
        }
    }
    if(minb==INF)cout<<0<<endl;
    else cout<<sum-minb<<endl;
}