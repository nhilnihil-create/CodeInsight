#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    ll n,m;
    cin>>n>>m;
    if(n==1&&m==1){
        cout<<1<<endl;
        return 0;
    }
    if(n==1||m==1){
        cout<<max(n,m)-2;
        return 0;
    }
    cout<<(n-2)*(m-2)<<endl;
}