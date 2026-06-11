#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    vector<ll> ab(n);
    for(int i=0; i<n; i++){
        ab[i]=b[i]-a[i];
    }
    sort(ab.begin(),ab.end());
    ll cnt=0,tmp=0;
    for(int i=0; i<n; i++){
        if(ab[i]>0){
            tmp+=ab[i];
            cnt++;
        }
    }
    for(int i=0; i<n; i++){
        if(tmp>0&&ab[i]<0){
            tmp+=ab[i];
            cnt++;
        }
    }
    if(tmp>0) cout<<-1<<endl;
    else cout<<cnt<<endl;
}