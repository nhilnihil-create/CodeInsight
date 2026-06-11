#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(){
    ll a,b;
    cin>>a>>b;
    ll flag=0;
    ll height;
    for(ll i=0;i<1000;++i){
        flag += i;
        if(i+1 == b-a){
            height = flag-a;
            break;
        }
    }
    cout<<height<<endl;
    return 0;
}