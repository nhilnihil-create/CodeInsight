#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        ll ok=0,ng=b+1;
        while(ng-ok>1){
            ll mid=(ok+ng)/2;
            ll mx;
            ll c=(a+mid)/2;
            if(c>=mid){
                mx=(a+1)*(mid-1);
            }
            else{
                mx=c*(a+mid-c);
            }
            if(mx<a*b)ok=mid;
            else ng=mid;
        }
        cout<<a+ok-2<<endl;
    }
}