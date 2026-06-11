#include <iostream>
using namespace std;
typedef long long ll;
int main(void){
    int n, a, b, d=1e9+7;
    ll c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        c+=b;
        if(b<a){
            d=min(d, b);
        }
    }
    if(d==1e9+7){
        cout<<0<<endl;
    }else{
        cout<<c-d<<endl;
    }
}