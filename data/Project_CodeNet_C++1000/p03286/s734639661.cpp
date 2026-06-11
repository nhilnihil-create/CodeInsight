#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

string s="";

int main(){
    ll n;
    cin>>n;
    ll nega=0;
    ll pos=0;
    ll now=1;
    if(n==0){cout<<0;return 0;}
    while(1){
        if(nega+now<=n&&n<=pos+now){
            break;
        }
        if(now>0){
            pos+=now;
        }else{
            nega+=now;
        }
        now*=-2;
    }
    while(now){
        if(nega+now<=n&&n<=pos+now){
            s+="1";
            n-=now;
        }else{
            s+="0";
        }
        now=-now/2;
        if(now>0){
            pos-=now;
        }else{
            nega-=now;
        }
    }
    cout<<s<<endl;

    return 0;
}