#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
int n;
ll a,b,c,d;
ll gcd(ll x,ll y){
    if(y==0)
        return x;
    return gcd(y,x%y);
}
int main(){
    cin>>n;
    while(n--){
        cin>>a>>b>>c>>d;
        if(a<b){
            cout<<"No"<<endl;
            continue;
        }
        if(b>d){
            cout<<"No"<<endl;
            continue;
        }
        // if(c+1>=b){
        //     cout<<"Yes"<<endl;
        //     continue;
        // }
        ll g=gcd(b,d);
        if((a-c-1ll)/g-(a-b)/g>0)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
} 