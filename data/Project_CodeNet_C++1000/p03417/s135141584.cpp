#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;

int main(){
    ll n,m;
    cin>>n>>m;

    if(n>1 && m>1){
        cout<<n*m-2*n-2*m+4<<endl;
    }else if(n==1 && m==1){
        cout<<1<<endl;
    }else if(n==1){
        cout<<m-2<<endl;
    }else{
        cout<<n-2<<endl;
    }
    return 0;
}