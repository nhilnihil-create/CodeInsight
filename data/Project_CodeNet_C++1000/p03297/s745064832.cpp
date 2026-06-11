#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
int t;
ll gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
ll a,b,c,d;

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a>>b>>c>>d;
        if(a<b){
            cout<<"No"<<endl;
        } else if(d<b){
            cout<<"No"<<endl;
        } else if(c-b-1>=0){
            cout<<"Yes"<<endl;
        } else{
            ll tmp = gcd(b,d);
            if((a-b)/tmp<(a-c-1)/tmp){
                cout<<"No"<<endl;
            } else{
                cout<<"Yes"<<endl;
            }
        }
    }
}

