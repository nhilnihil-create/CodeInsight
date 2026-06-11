#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll a[15];
int x=1,y=1;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        x*=3;
        if(a[i]%2==0){
            y*=2;
        }else{
            y*=1;
        }
    }
    cout<<x-y<<endl;

}

