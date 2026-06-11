#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k;
int main(void){
    cin>>n>>k;
    if(k%2==0){
        cout<<(n/k)*(n/k)*(n/k)+((n+k/2)/k)*((n+k/2)/k)*((n+k/2)/k)<<endl;
    }else{
        cout<<(n/k)*(n/k)*(n/k)<<endl;
    }
    
}
