#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

ll f(ll a){
    if(a==-1) return 0;
    else if(a%4==3) return 0;
    else if(a%4==2) return a^1;
    else if(a%4==1) return 1;
    else return a;
}

int main(){
    ll a,b;
    cin>>a>>b;
    cout<<(f(a-1)^f(b))<<endl;
    return 0;
}