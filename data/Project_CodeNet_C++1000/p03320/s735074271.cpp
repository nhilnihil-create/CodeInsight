#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll digsum(ll n){
    ll a=0;
    while (n) {
        a+=n%10;
        n/=10;
    }
    return a;
}
int main(){
    ll n;
    cin>>n;
    ll dis=1;
    ll cnt=1;
    while (n) {
        if(cnt*digsum(cnt+dis)<=(cnt+dis)*digsum(cnt)){
            cout<<cnt<<endl;
            n--;
            cnt+=dis;
        }
        else{
            dis*=10;
            cnt=(cnt/dis+1)*dis-1;
        }
    }
}