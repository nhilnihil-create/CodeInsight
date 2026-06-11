#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,a[N],b[N],flg,sum,m=(1e17);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        if(a[i]!=b[i])flg=1;
        sum+=a[i];
        if(a[i]>b[i])m=min(m,b[i]);
    }
    if(!flg)return cout<<"0" , 0;
    cout<<sum-m;
}
