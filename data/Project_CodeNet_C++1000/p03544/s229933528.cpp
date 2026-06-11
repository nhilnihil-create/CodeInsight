#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll l[100];
int main(void){
    cin>>n;
    l[0]=2; l[1]=1;
    for(int i=2;i<=n;i++){
        l[i]=l[i-1]+l[i-2];
    }
    cout<<l[n]<<endl;
    
}
