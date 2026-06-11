#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m;
ll k;
int main(void){
    cin>>n>>m;
    k=1900*m+(n-m)*100;
    for(int i=0;i<m;i++){
        k=k*2;
    }
    cout<<k<<endl;
    
}
